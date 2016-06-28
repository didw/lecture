import sys
from PyQt5 import uic
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *

class Form(QDialog):
    def __init__(self, parent=None):
        QDialog.__init__(self, parent)
        self.ui = uic.loadUi('hello_world.ui')
        self.ui.show()

app = QApplication(sys.argv)
w = Form()

app.exec()

