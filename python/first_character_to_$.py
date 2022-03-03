def string_replace(str1):
    char=str1[0]
    str1=str1.replace(char,'$')
    str1=char+str1[1:]
    return str1



str="restart"
print(string_replace(str))
