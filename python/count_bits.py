
def count_bits(x):
    numbits = 0
    while x:
        numbits = numbits + (x & 1)
        x = x >> 1
    return numbits

p = 23
print(count_bits(p))
