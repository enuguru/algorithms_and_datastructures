def uncommon_words(s,s1):
    count={}
    for x in s.split():
        count[x]=count.get(x,0)+1

    for x in s1.split():
        count[x]=count.get(x,0)+1

    return([word for word in count if count[word]==1])

s="My name is BadriNarayanan"
s1="My name is Karthik"
print(uncommon_words(s,s1))
