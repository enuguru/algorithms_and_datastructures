import csv
file=open('country.csv','r')
reader=csv.reader(file)
mylist=[]
for read in reader:
    mylist.append(read)

for i in mylist:
    print(i)
