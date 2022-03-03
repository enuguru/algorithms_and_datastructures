from ctypes import *
libCalc=CDLL("./libcalci.so")
libCalc.connect()
varAdd=libCalc.addNum(20,30)
print(varAdd)
