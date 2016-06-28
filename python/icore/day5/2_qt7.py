import sys
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5 import uic

class MyForm(QDialog):
    def __init__(self):
        super().__init__()
        self.ui = uic.loadUi('2_qt7.ui')
        self.ui.btn1.clicked.connect(self.btn_click1)
        self.ui.btn2.clicked.connect(self.btn_click2)
        self.ui.btn3.clicked.connect(self.btn_click3)
    def show(self):
        self.ui.show()
    def btn_click1(self):
        self.ui.textEdit.setText('btn1 clicked')
    def btn_click2(self):
        self.ui.textEdit.setText('btn2 clicked')
    def btn_click3(self):
        self.ui.textEdit.setText('btn3 clicked')


if __name__ == '__main__':
    app = QApplication(sys.argv)
    mainDlg = MyForm()
    mainDlg.show()
    app.exec()