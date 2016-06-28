import sys
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5 import uic
import libData

class DiagM(QDialog):
    def __init__(self, data):
        super().__init__()
        self.ui = uic.loadUi('lib_manage.ui')
        if data != '':
            self.setData(data)
        self.ui.btnRegister.clicked.connect(self.btnRegister)
        self.ui.btnSearch.clicked.connect(self.btnSearch)
        self.ui.btnUpdate.clicked.connect(self.btnUpdate)
        self.ui.btnDelete.clicked.connect(self.btnDelete)
        
    def show(self):
        self.ui.exec() # Modal dialog
    def readData(self):
        r = self.ui.leReg.text()
        d = self.ui.leDate.text()
        n = self.ui.leName.text()
        p = self.ui.lePub.text()
        a = self.ui.leAuthor.text()
        k = self.ui.leKind.text()
        e1 = self.ui.leEtc1.text()
        e2 = self.ui.leEtc2.text()
        e3 = self.ui.leEtc3.text()
        return (r, d, n, p, a, k, e1, e2, e3)
    def setData(self, data):
        r, d, n, p, a, k, e1, e2, e3 = data
        self.ui.leReg.setText(r)
        self.ui.leDate.setText(d)
        self.ui.leName.setText(n)
        self.ui.lePub.setText(p)
        self.ui.leAuthor.setText(a)
        self.ui.leKind.setText(k)
        self.ui.leEtc1.setText(e1)
        self.ui.leEtc2.setText(e2)
        self.ui.leEtc3.setText(e3)
        
    def btnRegister(self):
        d = self.readData()
        libData.insert_data(d[0],d[1],d[2],d[3],d[4],d[5],d[6],d[7],d[8])
        
    def btnSearch(self):
        reg = self.readData()[0]
        data = libData.search_data_by_reg(reg)
        self.setData(data[0])
        
    def btnUpdate(self):
        d = self.readData()
        libData.update_data(d[0],d[1],d[2],d[3],d[4],d[5],d[6],d[7],d[8])
        
    def btnDelete(self):
        libData.delete_data(self.readData()[0])

class DiagS(QDialog):
    def __init__(self):
        super().__init__()
        self.ui = uic.loadUi('lib_search.ui')
        self.ui.comboBox.addItems(['도서명','출판사','저자'])
        self.ui.btnSearch.clicked.connect(self.btnSearch)

    def show(self):
        self.ui.exec() # Modal dialog

    def btnSearch(self):
        idx = self.ui.comboBox.currentIndex()
        val = self.ui.leName.text()
        if idx == 0:
            data = libData.search_data_by_name(val)
        elif idx == 1:
            data = libData.search_data_by_pub(val)
        elif idx == 2:
            data = libData.search_data_by_author(val)
        print(data)
        self.table_clear()
        self.table_show(data)
    
    def table_clear(self):
        nRow = self.ui.tableWidget2.rowCount()
        for n in range(nRow,-1,-1):
            self.ui.tableWidget2.removeRow(n)
        self.ui.tableWidget2.setHorizontalHeaderLabels(
            ['도서명','출판사','저자'])
    
    def table_show(self, data):
        for d in data:
            self.table_data(d)
    
    def table_data(self, data):
        print(data)
        nRow = self.ui.tableWidget2.rowCount()
        self.ui.tableWidget2.setRowCount(nRow+1)
        self.ui.tableWidget2.setItem(nRow,0,QTableWidgetItem("aa"))
        self.ui.tableWidget2.setItem(nRow,1,QTableWidgetItem("11"))
        self.ui.tableWidget2.setItem(nRow,2,QTableWidgetItem("22"))


class mainLib(QDialog):
    def __init__(self):
        super().__init__()
        self.ui = uic.loadUi('lib_main.ui')
        self.ui.actionManage.triggered.connect(self.menu_manage)
        self.ui.actionSearch.triggered.connect(self.menu_search)
        self.table_init()
        self.ui.btnSearch.clicked.connect(self.btn_search)
        self.ui.btnAll.clicked.connect(self.btn_showall)
        self.ui.tableWidget.cellDoubleClicked.connect(self.table_double_clicked)

    def show(self):
        self.ui.show()

    def menu_manage(self):
        self.dlg = DiagM('')
        self.dlg.show()

    def menu_search(self):
        self.dlg = DiagS()
        self.dlg.show()
        
    def table_init(self):
        self.ui.tableWidget.setColumnCount(6)
        self.ui.tableWidget.setHorizontalHeaderLabels(
            ['관리번호','등록일','도서명','출판사','저자','도서종류'])
        self.data = libData.select_data()
        self.table_show(self.data)
    
    def btn_showall(self):
        self.ui.leName.setText('')
        self.ui.lePub.setText('')
        self.ui.leAuthor.setText('')
        self.table_clear()
        self.table_init()
    
    def table_double_clicked(self, r, c):
        print(self.data[r])
        self.dlgM = DiagM(self.data[r])
        self.dlgM.show()
        
        
    def btn_search(self):
        name = self.ui.leName.text()
        pub = self.ui.lePub.text()
        author = self.ui.leAuthor.text()
        self.ui.leName.setText('')
        self.ui.lePub.setText('')
        self.ui.leAuthor.setText('')
        if name != '':
            self.data = libData.search_data_by_name(name)
        elif pub != '':
            self.data = libData.search_data_by_pub(pub)
        elif author != '':
            self.data = libData.search_data_by_author(author)
        self.table_clear()
        self.table_show(self.data)
    
    def table_clear(self):
        nRow = self.ui.tableWidget.rowCount()
        for n in range(nRow,-1,-1):
            self.ui.tableWidget.removeRow(n)
        self.ui.tableWidget.setHorizontalHeaderLabels(
            ['관리번호','등록일','도서명','출판사','저자','도서종류'])
        
    def table_show(self, data):
        for d in data:
            self.table_data(d)
    
    def table_data(self, data):
        nRow = self.ui.tableWidget.rowCount()
        self.ui.tableWidget.setRowCount(nRow+1)
        for i in range(6):
            self.ui.tableWidget.setItem(nRow,i,QTableWidgetItem(data[i]))

if __name__ == '__main__':
    app = QApplication(sys.argv)
    mainDlg = mainLib()
    mainDlg.show()
    app.exec()
