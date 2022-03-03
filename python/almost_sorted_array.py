import itertools
import heapq
def almost_sorted(sequence,k):
    min_heap=[]
    sequence=iter(sequence)
    for x in itertools.islice(sequence,k):
        heapq.heappush(min_heap,x)

    result=[]
    for x in sequence:
        smallest=heapq.heappushpop(min_heap,x)
        result.append(smallest)

    while min_heap:
        result.append(heapq.heappop(min_heap))
    return result


sequence=[3,-1,2,6,4,5,8]
k=2
print(almost_sorted(sequence,k))
