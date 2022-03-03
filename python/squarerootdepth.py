
# this program is written by python level 1 student Upama
# this program finds the square root depth

import math
count = 0
sq = 0
num_dict = {}
for num in reversed(range(7001)):
    sq = math.sqrt(num)
    if sq == math.floor(sq):
        count += 1
        while sq >= 2:
            sq = math.sqrt(sq)
            if sq == math.floor(sq):
                count += 1
                continue
            num_dict.update({num : count})
            count = 0
            sq = 0
    else:
        continue

print(num_dict)
