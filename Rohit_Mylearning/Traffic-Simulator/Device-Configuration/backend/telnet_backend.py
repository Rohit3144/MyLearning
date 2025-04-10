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

            self.writer.write(username + "\n")
            await self.writer.drain()
            await asyncio.sleep(1)

            self.writer.write(password + "\n")
            await self.writer.drain()
            await asyncio.sleep(1)

            response = await self.reader.read(100)
            return True, response
        except Exception as e:
            return False, str(e)

    async def disconnect(self):
        if self.writer:
            self.writer.write("exit\n")
            await self.writer.drain()
            self.writer.close()
            await self.writer.wait_closed()
            return "Disconnected"
        return "No session to disconnect"


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
