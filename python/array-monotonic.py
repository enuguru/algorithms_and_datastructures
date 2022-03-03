def monotonic(m):
    return (all(m[i]<=m[i+1] for i in range(len(m)-1)) or
           all(m[i]>=m[i+1] for i in range(len(m)-1)))

mylist=[100,200,300]
print(monotonic(mylist))
