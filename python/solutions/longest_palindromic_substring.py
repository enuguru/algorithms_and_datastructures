def longest_palindromic_substring(s: str) -> str:
    def expand_around_center(left: int, right: int) -> str:
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return s[left + 1:right]
    
    if len(s) < 1:
        return ""
    
    longest = ""
    for i in range(len(s)):
        # Odd length palindrome
        palindrome = expand_around_center(i, i)
        if len(palindrome) > len(longest):
            longest = palindrome
        # Even length palindrome
        palindrome = expand_around_center(i, i + 1)
        if len(palindrome) > len(longest):
            longest = palindrome
    return longest

# Test
print(longest_palindromic_substring("babad"))  # Output: "bab" or "aba"
print(longest_palindromic_substring("cbbd"))   # Output: "bb"
