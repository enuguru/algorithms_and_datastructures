
from itertools import *

data = list(combinations_with_replacement('ABCD', 2))
for item in data:
    print(item)
