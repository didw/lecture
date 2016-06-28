import sys
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *

app = QApplication(sys.argv)

mainDlg = QDialog()
mainDlg.setGeometry(300, 300, 200, 200)
mainDlg.setWindowTitle('korea')
l1 = QLabel('hello1')
l2 = QLabel('hello2')
edit = QLineEdit('edit..')
btn = QPushButton('btn1')

layout = QVBoxLayout()
layout.addWidget(l1)
layout.addWidget(l2)
layout.addWidget(edit)
layout.addWidget(btn)
mainDlg.setLayout(layout)

mainDlg.show()

app.exec()

