import sys
from PyQt5.QtWidgets import QApplication
from telnet_gui import TelnetGUI


def main():
    app = QApplication(sys.argv)
    window = TelnetGUI()
    window.show()
    sys.exit(app.exec_())


if __name__ == "__main__":
    main()
