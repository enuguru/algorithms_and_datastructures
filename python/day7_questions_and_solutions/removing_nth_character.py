def remove_nth_character(s,n):
    n=n-1
    first=s[:n]
    second=s[n+1:]
    result=first+second
    print('Original string',s)
    print(result)


remove_nth_character('Python',2)
