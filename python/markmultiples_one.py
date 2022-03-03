
multiples = []

print("This program prints prime numbers in the given range using the sieve of eratosthenes algorithm")

for num in range(2,121):
    if(num not in multiples):
        print(num,end=" ")
        x = num + num
        for i in range(x,121,num):
            if(i not in multiples):
                 multiples.append(i)
    else:
        continue

print()

