# easy install 이용한 배포판 만들기
from setuptools import setup   # easy install tools

setup(name = "myeasy",
      version = "0.1",
      description = "test distribution",
      py_modules=["easy1", "easy2"]      
)

#### 1 >>> python setup.py sdist
#### 2 >>> easy_install myeasy-0.1.zip
