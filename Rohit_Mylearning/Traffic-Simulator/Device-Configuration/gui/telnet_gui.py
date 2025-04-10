from PyQt5.QtWidgets import (
    QWidget,
    QVBoxLayout,
    QLabel,
    QLineEdit,
    QPushButton,
    QTextEdit,
)
import requests


class TelnetGUI(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("OLT Telnet GUI")
        self.setGeometry(100, 100, 400, 300)
        self.init_ui()

    def init_ui(self):
        layout = QVBoxLayout()

        self.ip_input = QLineEdit("192.168.1.1")
        self.username_input = QLineEdit("root")
        self.password_input = QLineEdit("#A!rtel@321#")
        self.password_input.setEchoMode(QLineEdit.Password)

        self.connect_btn = QPushButton("Connect")
        self.disconnect_btn = QPushButton("Disconnect")
        self.output_box = QTextEdit()
        self.output_box.setReadOnly(True)

        self.status_label = QLabel("Status: Disconnected")

        self.connect_btn.clicked.connect(self.connect_telnet)
        self.disconnect_btn.clicked.connect(self.disconnect_telnet)

        layout.addWidget(QLabel("IP Address:"))
        layout.addWidget(self.ip_input)
        layout.addWidget(QLabel("Username:"))
        layout.addWidget(self.username_input)
        layout.addWidget(QLabel("Password:"))
        layout.addWidget(self.password_input)
        layout.addWidget(self.connect_btn)
        layout.addWidget(self.disconnect_btn)
        layout.addWidget(self.status_label)
        layout.addWidget(self.output_box)

        self.setLayout(layout)

    def connect_telnet(self):
        data = {
            "ip": self.ip_input.text(),
            "username": self.username_input.text(),
            "password": self.password_input.text(),
        }
        try:
            res = requests.post("http://127.0.0.1:8000/connect", json=data)
            if res.status_code == 200:
                self.status_label.setText("Status: Connected")
                self.output_box.append(res.json()["response"])
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
        except Exception as e:
            self.output_box.append(f"Exception: {e}")
