import sys
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5 import uic

class Diag1(QDialog):
    def __init__(self, txt):
        super().__init__()
        self.ui = uic.loadUi('2_qt11_diag.ui')
        self.ui.lineEdit.setText(txt)
    def show(self):
        #self.ui.show()
        self.ui.exec() # Modal dialog

class MyForm(QDialog):
    def __init__(self):
        super().__init__()
        self.ui = uic.loadUi('2_qt11_main.ui')
        self.ui.actionTest1.triggered.connect(self.menu_test1)
        self.ui.actionView1.triggered.connect(self.menu_view1)
        self.ui.actionView2.triggered.connect(self.menu_view2)

    def show(self):
        self.ui.show()

    def menu_test1(self):
        self.dlg = Diag1("test1 menu clicked")
        self.dlg.show()

    def menu_view1(self):
        self.ui.stackedWidget.setCurrentIndex(0)

    def menu_view2(self):
        self.ui.stackedWidget.setCurrentIndex(1)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    mainDlg = MyForm()
    mainDlg.show()
    app.exec()
