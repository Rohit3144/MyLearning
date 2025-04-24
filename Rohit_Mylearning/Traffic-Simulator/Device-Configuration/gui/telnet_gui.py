from PyQt5.QtWidgets import (
    QWidget,
    QVBoxLayout,
    QLabel,
    QPushButton,
    QTextEdit,
    QLineEdit,
    QMessageBox,
    QStackedLayout,
)
from PyQt5.QtCore import Qt, pyqtSignal
import requests
import re


# 🔹 Custom QLineEdit for command input with arrow key history + Ctrl+Enter
class CommandInputLineEdit(QLineEdit):
    returnPressedWithText = pyqtSignal(str)

    def __init__(self, parent=None):
        super().__init__(parent)
        self.history = []
        self.history_index = -1

    def keyPressEvent(self, event):
        key = event.key()
        modifiers = event.modifiers()

        if key == Qt.Key_Up:
            if self.history and self.history_index > 0:
                self.history_index -= 1
                self.setText(self.history[self.history_index])
        elif key == Qt.Key_Down:
            if self.history and self.history_index < len(self.history) - 1:
                self.history_index += 1
                self.setText(self.history[self.history_index])
            else:
                self.clear()
                self.history_index = len(self.history)
        elif key == Qt.Key_Return or key == Qt.Key_Enter:
            if modifiers == Qt.ControlModifier:
                # Optional: Add multiline support here
                pass
            else:
                text = self.text().strip()
                if text:
                    self.returnPressedWithText.emit(text)
        else:
            super().keyPressEvent(event)


class TelnetGUI(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("OLT Telnet GUI")
        self.setGeometry(100, 100, 500, 400)
        self.init_ui()

    def init_ui(self):
        self.stack = QStackedLayout()

        # --- Page 1: Connection Page ---
        self.connect_page = QWidget()
        connect_layout = QVBoxLayout()

        self.ip_input = QLineEdit("192.168.1.1")
        self.username_input = QLineEdit("root")
        self.password_input = QLineEdit("#A!rtel@321#")
        self.password_input.setEchoMode(QLineEdit.Password)

        self.connect_btn = QPushButton("Connect")
        self.disconnect_btn = QPushButton("Disconnect")
        self.status_label = QLabel("Status: Disconnected")
        self.output_box = QTextEdit()
        self.output_box.setReadOnly(True)
        self.to_command_btn = QPushButton("Next")
        self.to_command_btn.setEnabled(False)

        self.connect_btn.clicked.connect(self.connect_telnet)
        self.disconnect_btn.clicked.connect(self.disconnect_telnet)
        self.to_command_btn.clicked.connect(lambda: self.stack.setCurrentIndex(1))

        connect_layout.addWidget(QLabel("IP Address:"))
        connect_layout.addWidget(self.ip_input)
        connect_layout.addWidget(QLabel("Username:"))
        connect_layout.addWidget(self.username_input)
        connect_layout.addWidget(QLabel("Password:"))
        connect_layout.addWidget(self.password_input)
        connect_layout.addWidget(self.connect_btn)
        connect_layout.addWidget(self.disconnect_btn)
        connect_layout.addWidget(self.status_label)
        connect_layout.addWidget(self.output_box)
        connect_layout.addWidget(self.to_command_btn)

        self.connect_page.setLayout(connect_layout)
        self.stack.addWidget(self.connect_page)

        # --- Page 2: Command Page ---
        self.command_page = QWidget()
        command_layout = QVBoxLayout()

        self.command_input = CommandInputLineEdit()
        self.command_input.returnPressedWithText.connect(self.send_command)

        self.send_command_btn = QPushButton("Send Command")
        self.command_output_box = QTextEdit()
        self.command_output_box.setReadOnly(True)
        self.back_btn = QPushButton("Back")

        self.send_command_btn.clicked.connect(
            lambda: self.send_command(self.command_input.text())
        )
        self.back_btn.clicked.connect(lambda: self.stack.setCurrentIndex(0))

        command_layout.addWidget(QLabel("Enter Command:"))
        command_layout.addWidget(self.command_input)
        command_layout.addWidget(self.send_command_btn)
        command_layout.addWidget(QLabel("Output:"))
        command_layout.addWidget(self.command_output_box)
        command_layout.addWidget(self.back_btn)

        self.command_page.setLayout(command_layout)
        self.stack.addWidget(self.command_page)

        self.setLayout(self.stack)

    def connect_telnet(self):
        ip = self.ip_input.text().strip()
        username = self.username_input.text().strip()
        password = self.password_input.text()

        if not re.match(r"^(?:\d{1,3}\.){3}\d{1,3}$", ip):
            self.show_error("Invalid IP address. Please enter a valid IPv4 address.")
            return
        if not re.match(r"^[A-Za-z]+$", username):
            self.show_error("Username must contain alphabets only.")
            return
        if not re.match(
            r"^[A-Za-z0-9!@#$%^&*()_+\-=\[\]{};':\"\\|,.<>\/?`~]+$", password
        ):
            self.show_error(
                "Password can contain alphabets, numbers, and special characters."
            )
            return

        data = {"ip": ip, "username": username, "password": password}
        try:
            res = requests.post("http://127.0.0.1:8000/connect", json=data)
            if res.status_code == 200:
                self.status_label.setText("Status: Connected")
                self.output_box.append(res.json()["response"])
                self.to_command_btn.setEnabled(True)
            else:
                self.status_label.setText("Status: Failed")
                self.output_box.append("Error: " + res.json().get("detail", "Unknown"))
        except Exception as e:
            self.output_box.append(f"Exception: {e}")

    def disconnect_telnet(self):
        try:
            res = requests.post("http://127.0.0.1:8000/disconnect")
            self.status_label.setText("Status: Disconnected")
            self.output_box.append(res.json().get("response", ""))
            self.to_command_btn.setEnabled(False)
        except Exception as e:
            self.output_box.append(f"Exception: {e}")

    def send_command(self, cmd: str):
        cmd = cmd.strip()
        if not cmd:
            self.show_error("Please enter a command.")
            return

        try:
            res = requests.post("http://127.0.0.1:8000/command", json={"command": cmd})
            if res.status_code == 200:
                output = res.json()["response"]
                self.command_output_box.append(f"> {cmd}\n{output}\n")

                # Log the command
                with open("telnet_log.txt", "a") as f:
                    f.write(f"> {cmd}\n{output}\n\n")

                # Add to history
                self.command_input.history.append(cmd)
                self.command_input.history_index = len(self.command_input.history)
            else:
                self.command_output_box.append(
                    f"Error: {res.json().get('detail', 'Unknown')}"
                )
        except Exception as e:
            self.command_output_box.append(f"Exception: {e}")
        finally:
            self.command_input.clear()
            self.command_input.setFocus()

    def show_error(self, message):
        QMessageBox.critical(self, "Validation Error", message)
