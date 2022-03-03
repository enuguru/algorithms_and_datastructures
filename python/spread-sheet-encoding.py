#Program to find value for spread-sheet-encoding
import functools
s='AA'
def column_encoding(s):
    return functools.reduce(lambda result,c:result*26+ord(c)-ord('A')+1,s,0)

print(column_encoding(s))
