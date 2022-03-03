def count_character(str1,str2):
    c,j=0,0
    for i in str1:
        if str2.find(i)>=0 and j==str1.find(i):
            c=c+1
        j=j+1

    print('Number of matching characters',c)

str1="aaabrtv"
str2="bv"
count_character(str1,str2)

