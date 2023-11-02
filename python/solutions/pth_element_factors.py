def pth_factor(number, p):
    # Finding the factors of the number
    factors = [i for i in range(1, number + 1) if number % i == 0]
    
    # Sorting the factors in ascending order
    factors.sort()
    
    # Return the pth element if it exists, otherwise return 0
    if p - 1 < len(factors):
        return factors[p - 1]
    else:
        return 0

# Test cases
print(pth_factor(28, 2))  # Output: 2 (Factors of 28: [1, 2, 4, 7, 14, 28])
print(pth_factor(15, 5))  # Output: 0 (Factors of 15: [1, 3, 5, 15], 5th element does not exist)
