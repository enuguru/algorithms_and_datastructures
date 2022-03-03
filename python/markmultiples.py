
multiples = []

for num in range(2,121):
    if(num not in multiples):
        print(num,end=" ")
        for i in range(num+1,121):
            if((i % num) == 0):
                multiples.append(i)
