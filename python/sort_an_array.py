def increasing_decreasing_array(A):
    increasing,decreasing=range(2)
    sort_type=increasing
    sort_array=[]
    start_index=0
    for i in range(1,len(A)+1):
        if((i==len(A)) or (A[i-1]<A[i] and sort_type==decreasing) or (A[i-1]>=A[i] and sort_type==increasing)):
            sort_array.append(A[start_index:i] if sort_type==increasing else A[i-1:start_index-1:-1])
            sort_type=(increasing if sort_type==decreasing else decreasing)
            start_index=i

    return sort_array


A=[57,131,493,294,221,339,418,452,442,190]
print(increasing_decreasing_array(A))

