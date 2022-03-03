n=5
result=[[1]*(i+1) for i in range(n)]
for i in range(2,n):
    for j in range(1,i):
        result[i][j]=result[i-1][j-1]+result[i-1][j]

for i in result:
    print(i)
