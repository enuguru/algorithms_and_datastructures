def fibonacci(n):
    a,b=0,1
    print(a)
    print(b)
    while not b>n:
        c=a+b
        a,b=b,c
        print(c)
        


fibonacci(20)


