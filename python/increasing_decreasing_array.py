
import heapq
result=[]
min_heap=[]

def sorting_sequence(mylist):
    iter_list=[iter(x) for x in mylist]
    for i,it in enumerate(iter_list):
        first_element=next(it,None)
        if first_element is not None:
            heapq.heappush(min_heap,(first_element,i))

    while min_heap:
        min_element,min_index=heapq.heappop(min_heap)
        result.append(min_element)
        myiter=iter_list[min_index]
        next_element=next(myiter,None)
        if next_element is not None:
            heapq.heappush(min_heap,(next_element,min_index))

    return result

def sort_increasing_decreasing_array():
    A=[57,131,493,294,221,339,418,452,442,190]
    increasing,decreasing=range(2)
    merged_list=[]
    start_idx=0
    subarray_type=increasing
    for i in range(1,len(A)+1):
        if (i==len(A) or
            (A[i-1]<A[i] and subarray_type==decreasing) or
            (A[i-1]>A[i] and subarray_type==increasing)):
            merged_list.append(A[start_idx:i] if subarray_type==increasing else A[i-1:start_idx-1:-1])
            subarray_type=decreasing if subarray_type==increasing else increasing
            start_idx=i

    return sorting_sequence(merged_list)

print((sort_increasing_decreasing_array()))
            

