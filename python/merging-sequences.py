import heapq
def merge_sequence(mylist):
    my_iter=[iter(x) for x in mylist]
    min_heap=[]
    result=[]
    for i,ele in enumerate(my_iter):
        element=next(ele,None)
        if element is not None:
            heapq.heappush(min_heap,(element,i))

    while min_heap:
        element,index=heapq.heappop(min_heap)
        if element is not None:
            result.append(element)

        iter_list=my_iter[index]
        smallest=next(iter_list,None)
        if smallest is not None:
            heapq.heappush(min_heap,(smallest,index))
    return result
        


mylist=[(3,5,7),(0,6),(0,6,8)]
print(merge_sequence(mylist))
