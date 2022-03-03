
import itertools
c=itertools.repeat(100,times=5)
#print(next(c))
#print(next(c))

for i in c:
    print(i)

square=itertools.starmap(pow,[(0,2),(1,2),(2,2)])

for i in square:
    print(i)
#print(list(square))
