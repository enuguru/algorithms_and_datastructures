def largest(arr):
    max=0
    for i in range(len(arr)):
        if arr[i]>max:
            max=arr[i]
    return max


l=[1,2,100,5]
print(largest(l))

