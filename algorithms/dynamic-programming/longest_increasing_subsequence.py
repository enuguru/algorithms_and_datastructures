
# longest increasing subsequence

def lengthOfLIS(nums):
    dp = [1] * len(nums)
    for i in range(1, len(nums)):
        for j in range(i):
            if nums[i] > nums[j]:
                dp[i] = max(dp[i], dp[j] + 1)
    print(dp)
    return max(dp)

yourlist = [3,4,-1,0,6,2,3]
maxdp = lengthOfLIS(yourlist)
print("The length of the longest increasing subsequence is",maxdp)
