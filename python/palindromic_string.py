def is_palindrome(s):
    return all(a==b for a,b in zip(
        map(str.lower,filter(str.isalnum,s)),
        map(str.lower,filter(str.isalnum,reversed(s)))))

s="Able was I,ere I saw Elba!"
print(is_palindrome(s))

