import itertools
import heapq
li=[3,-1,2,6,4,5,8]
sequence=iter(li)
min_heap=[]
result=[]
for x in itertools.islice(sequence,2):
    heapq.heappush(min_heap,x)

for x in sequence:
    smallest=heapq.heappushpop(min_heap,x)
    result.append(smallest)

while min_heap:
    result.append(heapq.heappop(min_heap))

print(result)
