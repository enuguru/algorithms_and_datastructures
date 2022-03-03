x=[[1,2,3],
   [4,5,6]]

y=[[11,12],
   [21,22],
   [31,32]]

l=[[(xrow,yrow) for yrow in zip(*y) for xrow in x]]

product=[[sum(a*b for a,b in zip(xrow,yrow)) for yrow in zip(*y)] for xrow in x]
print(product)
