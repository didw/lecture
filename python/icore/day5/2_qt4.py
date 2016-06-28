import sys
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *

def btn_click():
    print("btn clicked")
    
class MyForm(QDialog):
    def __init__(self):
        super().__init__()
        self.setGeometry(300, 300, 200, 200)
        self.setWindowTitle('korea')        
        
        l1 = QLabel('hello1')
        l2 = QLabel('hello2')
        edit = QLineEdit('edit..')
        btn = QPushButton('btn1')
        btn.clicked.connect(btn_click)
        
        ## Layout
        layout = QVBoxLayout()
        layout.addWidget(l1)
        layout.addWidget(l2)
        layout.addWidget(edit)
        layout.addWidget(btn)
        self.setLayout(layout)
        
        self.show()


if __name__ == '__main__':
    app = QApplication(sys.argv)
    w = MyForm()
    app.exec()