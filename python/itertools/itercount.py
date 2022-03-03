import itertools

mylist=[1,2,3,4]
countvalue = itertools.count(start=5,end=10)
for i in countvalue:
    print(i)

g=list(itertools.zip_longest(range(10),mylist))
print(g)
