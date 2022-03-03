from collections import Counter

s='karthik'
w=Counter(s)
j=0
for x in w.values():
    if x>1:
        print(w.keys()[j])
    j=j+1


