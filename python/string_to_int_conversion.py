import functools
import string
def string_to_int(n):
    return functools.reduce(lambda r,i:r*10+string.digits.index(i),n[n[0]=='-':],0) * (-1 if n[0]=='-' else 1)

print(string_to_int("314"))

