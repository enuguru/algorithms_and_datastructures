import heapq
li=[4,10,1,2,100]
heapq.heapify(li)
print('The modified heap is')
print(list(li))
print(heapq.heappop(li))
print(heapq.nlargest(2,li))
