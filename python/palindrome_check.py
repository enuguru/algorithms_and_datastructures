def check_palindrome(s):
    return all(s[i]==s[~i] for i in range(len(s)//2))

s="malayalam"
print(check_palindrome(s))
