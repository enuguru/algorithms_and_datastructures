import itertools
mylist=[1,2,-1,10,11,20,100,-200]
a=[n for n in mylist if n>0]
count=[n>0 for n in mylist]
print(count)
result=list(itertools.compress(mylist,count))
print(result)
