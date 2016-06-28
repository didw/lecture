from distutils.core import setup

setup(name = "myLG",
      version = "0.1",
      description = "test distribution",
      packages=["LG", "LG.com", "LG.ui"]      
)

#### 1 >>> python setup.py sdist
#### 2 >>> pip install myDist-0.1.zip
