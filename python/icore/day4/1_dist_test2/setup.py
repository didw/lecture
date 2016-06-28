# window 바이너리 배포판 만들기
from distutils.core import setup

setup(name = "myWIN",
      version = "0.1",
      description = "test distribution",
      py_modules=["win1", "win2"]      
)

#### 1 >>> python 1_setup2.py bdist_wininst
#### 2 : double click myWIN-0.1.win32.exe
