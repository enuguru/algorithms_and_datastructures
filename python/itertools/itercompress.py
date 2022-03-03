import itertools
def even_numbers(n):
    if n%2==0:
        return True
    return False

letters=['a','b','c','d']
numbers=[1,2,3,4,5]
result=filter(even_numbers,numbers)
print(list(result))
selectors=[True,False,True,False]
result=itertools.compress(letters,selectors)
print(list(result))
