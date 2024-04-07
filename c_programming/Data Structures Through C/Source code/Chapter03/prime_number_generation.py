# generate a list of the prime numbers till 100

def is_prime(n):
    for i in range(2, n):
        if n % i == 0:
            break
    else:
        print(n,end=" ")    # print the prime number

for i in range(2,100):
    is_prime(i)

