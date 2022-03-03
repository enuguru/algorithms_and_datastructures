def array_rotate(arr,position):
    n=len(arr)
    for i in range(position):
        x=arr[0]
        for j in range(len(arr)-1):
                arr[j]=arr[j+1]

        arr[n-1]=x

arr=[12,10,1,2,3,4]
array_rotate(arr,2)
print(arr)
