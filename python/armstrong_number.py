def armstrong(n):
    sums=0
    for i in range(1,n):
        num=i
        while i!=0:
            d=i%10
            sums=sums+d*d*d
            i=i/10

        if sums==num:
            print(num)
            sums=0
        else:
            sums=0

armstrong(1000)

