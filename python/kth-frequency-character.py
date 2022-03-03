NO_OF_CHARS=256
def kth_frequency(string,n,k):
    mydict={}
    count=0
    for i in range(n):
        if string[i] in mydict:
            mydict[string[i]]+=1
        else:
            mydict[string[i]]=1
        

    sorted_list=sorted(mydict.values(),reverse=True)
    kth_character_freq=sorted_list[k-1]
    print(mydict)
    for k,v in mydict.items():
        if v==kth_character_freq:
            if count==0:
                key=k
            count=count+1

    if count>1:
        print(key,-1)
    elif count==1:
        print(key,kth_character_freq)


    




string="karthik"
n=len(string)
k=2
kth_frequency(string,n,k)


