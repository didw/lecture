import sys
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5 import uic

class MyForm(QDialog):
    def __init__(self):
        super().__init__()
        self.ui = uic.loadUi('2_qt9.ui')
        self.ui.btn.clicked.connect(self.sumAB)

    def show(self):
        self.ui.show()

    def sumAB(self):
        a = self.ui.sbA.value()
        b = self.ui.sbB.value()
        self.ui.leResult.setText("{} + {} = {}".format(a, b, a+b))

if __name__ == '__main__':
    app = QApplication(sys.argv)
    mainDlg = MyForm()
    mainDlg.show()
    app.exec()
