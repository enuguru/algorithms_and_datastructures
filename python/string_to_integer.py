import string
import functools
def string_to_int(s):
    return functools.reduce(lambda val,c:val*10+string.digits.index(c),s[s[0]=='-':],0)

s='314'
print(string_to_int(s))
