
# Enter your code here. Read input from STDIN. Print output to STDOUT

val = int(input())
arraylist = sorted(list(map(int,input().split())))

print(sum(arraylist) / len(arraylist))

if val%2 == 0:
    median = (arraylist[int(val//2)-1] + arraylist[int(val//2)])/2
else:
    median = arraylist[(int(val+1)//2)]
print(median)

mode = max(sorted(arraylist), key=arraylist.count)
print(mode)
