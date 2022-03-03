ONE=1
TWO=2
def toList(string):
    l=[]
    for x in string:
        l.append(x)
    return l

def toString(string):
    return ''.join(string)

def remove_characters(string):
    j=0
    state=ONE
    for i in range(len(string)):
        if state==ONE and string[i]!='a' and string[i]!='b':
            string[j]=string[i]
            j+=1

        if state==TWO and string[i]!='c':
            string[j]='a'
            j+=1

            if string[i]!='a' and string[i]!='b':
                string[j]=string[i]
                j+=1

        state=TWO if string[i]=='a' else ONE

    if state==TWO:
        string[j]='a'
        j+=1

    return(toString(string[:j]))


print(remove_characters(toList("ababaac")))

