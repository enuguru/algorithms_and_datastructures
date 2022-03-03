from itertools import accumulate
import operator
numbers=[0,1,2,3,4]
c=itertools.accumulate(numbers)
print(list(c))
