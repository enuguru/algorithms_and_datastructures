
# python program to find the longest common subsequence

def longestCommonSubsequence(text1, text2):
       
    # Make a grid of 0's with len(text2) + 1 columns 
    # and len(text1) + 1 rows.
    result = 0
    dp_grid = [[0] * (len(text2) + 1) for _ in range(len(text1) + 1)]
        
    # Iterate up each column, starting from the last one.
    for col in range(len(text2)):
        for row in range(len(text1)):
            # If the corresponding characters for this cell are the same...
            if text2[col] == text1[row]:
                dp_grid[row][col] = 1 + dp_grid[row - 1][col - 1]
                result = max(result,dp_grid[row][col])
            # Otherwise they must be different...
            else:
                dp_grid[row][col] = 0
        
    # The original problem's answer is in dp_grid[0][0]. Return it.
    #return max(dp_grid[len(text1)-1][len(text2)-1]
    return result


strone = "abcdaf"
strtwo = "acbcf"
lenstr = longestCommonSubsequence(strone,strtwo)
print("The length of the longest common subsequence is",lenstr)
