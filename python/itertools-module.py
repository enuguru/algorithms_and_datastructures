
import itertools
mylist=[80,100,80,70,100]
for x in itertools.islice(mylist,2):
    print(x)
string="AABBBBCCDDD"
unique_vals=[]
groups=[]
mylist=sorted(mylist)
for x,v in itertools.groupby(mylist):
    unique_vals.append(x)
    groups.append(len(list(v)))

print(groups)
print(unique_vals)

s=sorted(string)
groupby=[len((list(g))) for k,g in itertools.groupby(s)]
print(groupby)
