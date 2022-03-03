def prime_interval(n1,n2):
    flag=0
    for i in range(n1,n2):
        for j in range(2,i):
            if i % j == 0:
                break
        else:
            print(i)
            
        

prime_interval(2,100)
            
