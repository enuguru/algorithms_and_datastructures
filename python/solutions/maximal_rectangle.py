def maximalRectangle(matrix):
    if not matrix:
        return 0

    n = len(matrix)
    m = len(matrix[0])
    h = [0] * m
    l = [0] * m
    r = [m] * m
    max_area = 0
    
    for i in range(n):
        left, right = 0, m
        for j in range(m):
            if matrix[i][j] == '1':
                h[j] += 1
                l[j] = max(l[j], left)
            else:
                left = j + 1
                h[j] = 0
                l[j] = 0
                r[j] = m
                
        for j in range(m - 1, -1, -1):
            if matrix[i][j] == '1':
                r[j] = min(r[j], right)
                max_area = max(max_area, (r[j] - l[j]) * h[j])
            else:
                right = j
    return max_area

# Test
matrix = [
    ["1", "0", "1", "0", "0"],
    ["1", "0", "1", "1", "1"],
    ["1", "1", "1", "1", "1"],
    ["1", "0", "0", "1", "0"]
]
print(maximalRectangle(matrix))  # Output: 6
