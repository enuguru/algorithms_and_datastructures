import heapq
def k_largest(mylist,k):
    max_heap=[]
    results=[]
    max_heap.append((-mylist[0],0))
    for _ in range(k):
        index=max_heap[0][1]
        results.append(-heapq.heappop(max_heap)[0])
        left_child_index=2*index+1
        if left_child_index<len(mylist):
            heapq.heappush(max_heap,(-mylist[left_child_index],left_child_index))

        right_child_index=2*index+2
        if right_child_index<len(mylist):
            heapq.heappush(max_heap,(-mylist[right_child_index],right_child_index))
        

    return results


mylist=[561,314,401,28,156,359,271,11,3]
print(k_largest(mylist,4))
