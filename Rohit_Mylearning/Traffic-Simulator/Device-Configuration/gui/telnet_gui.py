from PyQt5.QtWidgets import (
    QWidget,
    QVBoxLayout,
    QLabel,
    QLineEdit,
    QPushButton,
    QTextEdit,
    QMessageBox,
    QStackedLayout,
    QHBoxLayout,
)
import requests
import re


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
        self.to_command_btn = QPushButton("Go to Command Page")
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

        self.command_input = QLineEdit()
        self.send_command_btn = QPushButton("Send Command")
        self.command_output_box = QTextEdit()
        self.command_output_box.setReadOnly(True)
        self.back_btn = QPushButton("Back to Connection Page")

        self.send_command_btn.clicked.connect(self.send_command)
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

    def send_command(self):
        cmd = self.command_input.text().strip()
        if not cmd:
            self.show_error("Please enter a command.")
            return
        try:
            res = requests.post("http://127.0.0.1:8000/command", json={"command": cmd})
            if res.status_code == 200:
                self.command_output_box.append(f"> {cmd}\n{res.json()['response']}\n")
            else:
                self.command_output_box.append(
                    f"Error: {res.json().get('detail', 'Unknown')}"
                )
        except Exception as e:
            self.command_output_box.append(f"Exception: {e}")

    def show_error(self, message):
        QMessageBox.critical(self, "Validation Error", message)
