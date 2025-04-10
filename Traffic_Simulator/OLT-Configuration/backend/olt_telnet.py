import subprocess
import time
import pyautogui
import psutil

# Define MobaXterm executable path
mobaxterm_path = r"C:\Program Files (x86)\Mobatek\MobaXterm\MobaXterm.exe"  # Update this if necessary

# Telnet session details
host = "192.168.1.1"
username = "root"
password = "#A!rtel@321#"


def is_mobaxterm_running():
    """Check if MobaXterm is already running."""
    for process in psutil.process_iter(attrs=["pid", "name"]):
        if "MobaXterm.exe" in process.info["name"]:
            return True
    return False


# Step 1: Launch MobaXterm if not already running
if not is_mobaxterm_running():
    try:
        subprocess.Popen(mobaxterm_path)  # Open MobaXterm
        time.sleep(5)  # Wait for MobaXterm to open
    except Exception as e:
        print(f"Error launching MobaXterm: {e}")
        exit(1)
else:
    print("MobaXterm is already running.")

# Step 2: Open a new session using an existing configuration
pyautogui.hotkey("ctrl", "o")  # Open the session list
time.sleep(2)

# Step 3: Search for the saved session name (assuming it exists)
session_name = "192.168.1.1"  # Update if your saved session has a different name
pyautogui.write(session_name)
time.sleep(1)
pyautogui.press("enter")  # Open the saved session
time.sleep(5)  # Wait for Telnet session to open

# Step 4: Enter Username (if prompted)
pyautogui.write(username)
pyautogui.press("enter")
time.sleep(2)

# Step 5: Enter Password
pyautogui.write(password)
pyautogui.press("enter")
time.sleep(2)

print("Telnet session established successfully in MobaXterm!")
