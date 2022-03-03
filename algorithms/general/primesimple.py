
#list of prime numbers in the range with simple logic
print([x for x in range(5, 1000)
     if all(x % y != 0 for y in range(2, x))])
