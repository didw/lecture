import mylib
# import py_compile
# py_compile.compile('usermodule.py')
def main():
    rst = mylib.gop(10, 20)
    print(rst)
    print("__name__ ==>", __name__)
    print( type(__name__))

if __name__ == '__main__':
    main()



# import sys
# from mylib import *
# # import mylib
# # print(sys.path)
# # sys.path.append("d:\\my")
# # rst = mylib.gop(10, 20)
# # print(rst)
# # rst = mylib.hap(20, 30)
# # print(rst)
# rst = hap(10,20)
# print(rst)