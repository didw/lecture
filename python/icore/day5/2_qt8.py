import sys
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5 import uic

class MyForm(QDialog):
    def __init__(self):
        super().__init__()
        self.ui = uic.loadUi('2_qt8.ui')
        self.ui.btn.clicked.connect(self.btn_click)
    def show(self):
        self.ui.show()
    def btn_click(self):
        name = self.ui.leName.text()
        age = self.ui.sbAge.value()
        self.ui.leResult.setText("name: {}, age: {}".format(name, age))

if __name__ == '__main__':
    app = QApplication(sys.argv)
    mainDlg = MyForm()
    mainDlg.show()
    app.exec()
