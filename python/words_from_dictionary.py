def char_count(s):
    dict={}
    for i in s:
        dict[i]=dict.get(i,0)+1

    return dict


def words_formation(s,v):
    for i in s:
        flag=1
        chars=char_count(i)
        for key in chars:
            if key not in v:
                flag=0

        if flag==1:
            print(i)


input = ['go', 'bat', 'me', 'eat', 'goal', 'boy', 'run'] 
charSet = ['e', 'o', 'b', 'a', 'm', 'g', 'l'] 
words_formation(input,charSet)
