import heapq
def median(mylist):
    result=[]
    min_heap=[]
    max_heap=[]
    for x in mylist:
        heapq.heappush(max_heap,-heapq.heappushpop(min_heap,x))
        if len(max_heap)>len(min_heap):
            heapq.heappush(min_heap,-heapq.heappop(max_heap))

        result.append(0.5*(min_heap[0]+(-max_heap[0])) if 
                      len(max_heap)==len(min_heap) else min_heap[0])

    return result

mylist=[1,0,3,5,2,0,1]
print(median(mylist))

