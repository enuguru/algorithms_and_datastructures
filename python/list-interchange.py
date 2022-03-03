def list_interchange(l,pos1,pos2):
    l[pos1],l[pos2]=l[pos2],l[pos1]

l=[1,2,3,4,5,6,7,8,9]
list_interchange(l,2,5)
print(l)
