def monotone(arr):
    return(all(arr[i]<=arr[i+1] for i in range(len(arr)-1)) or
           all(arr[i]>=arr[i+1] for i in range(len(arr)-1)))


arr=[10,9,8,7]
print(monotone(arr))
           
