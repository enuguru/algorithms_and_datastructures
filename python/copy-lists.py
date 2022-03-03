def copy_list(l):
    list1=[]
    list1=l[:]
    return list1

l=[1,2,3,4]
l2=copy_list(l)
print(l2)
