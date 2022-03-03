import random
def kth_largest_element(A,p):
    def k_largest(left,right,k):
        pivot_value=A[k]
        A[k],A[right]=A[right],A[k]
        new_pivot=left
        for i in range(left,right):
            if A[i]>pivot_value:
                A[i],A[new_pivot]=A[new_pivot],A[i]
                new_pivot+=1

        A[right],A[new_pivot]=A[new_pivot],A[right]
        return new_pivot

    left=0
    right=len(A)-1
    while(left<=right):
        new_pivot_index=random.randint(left,right)
        new_pivot=k_largest(left,right,new_pivot_index)
        if (new_pivot==p-1):
            return A[new_pivot]
        elif new_pivot>p-1:
            right=new_pivot-1
        else:
            left=new_pivot+1
                

mylist=[3,2,1,5,4,100]
print(kth_largest_element(mylist,1))
