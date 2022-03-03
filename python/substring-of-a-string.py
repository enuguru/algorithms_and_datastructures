def substring(s):
    string=[s[i:j] for i in range(len(s)) for j in range(i+1,len(s)+1)]
    string=sorted(string)
    print(string)
    for i in range(len(string)):
        if string[i]=='badri':
            print('The rank of badri is',i+1)
            break


s='badri'
substring(s)
