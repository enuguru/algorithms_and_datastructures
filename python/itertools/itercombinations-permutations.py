
import itertools
letters=['a','b','c','d']
numbers=[1,2,3,4]
result=itertools.combinations(letters,2)
permute=itertools.permutations(letters,2)
print(list(result))
print(list(permute))
result=itertools.combinations(numbers,2)
permute=itertools.permutations(numbers,2)
print(list(result))
print(list(permute))
result=itertools.combinations(numbers,4)
permute=itertools.permutations(numbers,4)
print(list(result))
print(list(permute))
#cartisian_product=itertools.product(numbers,repeat=2)
#for item in cartisian_product:
#    print(item)
