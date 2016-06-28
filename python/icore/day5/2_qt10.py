import sys
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5 import uic

class MyForm(QDialog):
    def __init__(self):
        super().__init__()
        self.ui = uic.loadUi('2_qt10.ui')
        self.ui.listWidget.addItems(['lg1', 'lg2', 'lg3'])
        self.ui.comboBox.addItems(['lg4', 'lg5', 'lg6'])
        self.ui.btn.clicked.connect(self.btn_clicked_date)
        self.ui.listWidget.currentItemChanged.connect(self.list_changed)
        self.ui.comboBox.currentIndexChanged.connect(self.combobox_changed)
        self.table_init()
        
    def show(self):
        self.ui.show()
    
    def list_changed(self):
        item = self.ui.listWidget.currentItem().text()
        self.ui.lineEdit.setText(item)
    
    def combobox_changed(self):
        item = self.ui.comboBox.currentText()
        self.ui.lineEdit.setText(item)

    def table_init(self):
        self.ui.tableWidget.setColumnCount(2)
        self.ui.tableWidget.setHorizontalHeaderLabels(['Name', 'Age'])
        self.table_data("홍길동", 30)
        self.table_data("이순신", 50)
    
    def table_data(self, name, age):
        nRow = self.ui.tableWidget.rowCount()
        self.ui.tableWidget.setRowCount(nRow+1)
        self.ui.tableWidget.setItem(nRow,0,QTableWidgetItem(name))
        self.ui.tableWidget.setItem(nRow,1,QTableWidgetItem(str(age)))

    def btn_clicked(self):
        if self.ui.rbRed.isChecked():
            self.ui.lineEdit.setText("red")
        if self.ui.rbBlue.isChecked():
            self.ui.lineEdit.setText("blue")
        if self.ui.rbYellow.isChecked():
            self.ui.lineEdit.setText("yellow")

    def btn_clicked_date(self):
        dt = self.ui.dateEdit.date()
        self.ui.lineEdit.setText("{}, {}, {}".format(dt.year(), dt.month(), dt.day()))

if __name__ == '__main__':
    app = QApplication(sys.argv)
    mainDlg = MyForm()
    mainDlg.show()
    app.exec()
