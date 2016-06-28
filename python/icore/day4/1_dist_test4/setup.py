# 확장파이썬 배포
from distutils.core import setup, Extension

setup(name = "myextest",
      version = "0.1",
      description = "extension python test distribution",
      ext_packages="myc",
      ext_modules=[ Extension('extest', ['extest.c']) ]      
)

#### 1 >>> python setup.py sdist
#### 2 >>> pip install myextest-0.1.zip
