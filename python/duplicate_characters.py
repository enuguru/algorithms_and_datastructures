from collections import Counter
def duplicate_characters(s):
    dict={}
    dict=Counter(s)
    j=-1
    for i in dict.values():
        j=j+1
        if i>1:
            print(dict.keys()[j])


input="geeksforgeeks"
duplicate_characters(input)
