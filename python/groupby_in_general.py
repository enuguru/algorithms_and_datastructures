import itertools
mylist=[("a",1),("a",2),("b",4),("b",5)]
key=lambda x:x[0]

for keys,group in itertools.groupby(mylist,key):
    print keys,':',list(group)
