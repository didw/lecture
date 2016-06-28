from ctypes import *
import extest

def c_div(a,b):
    try:
        result = extest.divide(a,b)
        return result
    except Exception as err:
        return "error: {}".format(err)

print(c_div(3,2))
print(c_div(3,0))
