
def substring_vowels(str,k):
    mylist=list(str)
    vowels='aeiou'
    n=len(mylist)
    max=0
    for i in range(0,(n-k)+1):
        final = [mylist[each] for each in range(i,k+i) if mylist[each] in vowels]
        if len(final)>max:
            max=len(final)
            str=''.join(mylist[i:(k+i)])
    print(str)


