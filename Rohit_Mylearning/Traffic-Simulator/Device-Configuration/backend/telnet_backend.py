from fastapi import FastAPI, HTTPException
from pydantic import BaseModel
import asyncio
import telnetlib3

app = FastAPI()


class TelnetRequest(BaseModel):
    ip: str
    username: str
    password: str


class TelnetSession:
    def __init__(self):
        self.reader = None
        self.writer = None

    async def connect(self, ip, username, password):
        try:
            self.reader, self.writer = await telnetlib3.open_connection(
                host=ip, port=23, shell=None
            )

            # Send username
            self.writer.write(username + "\n")
            await self.writer.drain()
            await asyncio.sleep(1)

            # Send password
            self.writer.write(password + "\n")
            await self.writer.drain()
            await asyncio.sleep(1)

            # Discard login prompt/shell banner
            await self.reader.read(1024)

            return True, "Login successful"
        except Exception as e:
            return False, str(e)

    async def disconnect(self):
        if self.writer:
            try:
                self.writer.write("exit\n")
                await self.writer.drain()
                self.writer.close()  # No wait_closed(), not supported by telnetlib3
                self.reader = None
                self.writer = None
                return "Disconnected successfully"
            except Exception as e:
                return f"Error while disconnecting: {e}"
        return "No session to disconnect"


# Create a singleton Telnet session
telnet = TelnetSession()


@app.post("/connect")
async def connect(req: TelnetRequest):
    success, response = await telnet.connect(req.ip, req.username, req.password)
    if success:
        return {"status": "connected", "response": response}
    raise HTTPException(status_code=400, detail=response)


@app.post("/disconnect")
async def disconnect():
    msg = await telnet.disconnect()
    return {"status": "disconnected", "response": msg}
