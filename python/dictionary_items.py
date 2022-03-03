import operator
d={'Jayashree':250,'Guru':500,'Badri':200,'Karthik':300}
d1=sorted(d.items(),reverse=True)
d2=sorted(d.items(),key=operator.itemgetter(1))
d3=sorted(d.items(),key=operator.itemgetter(1),reverse=True)
for k,v in d.items():
    print(v)
