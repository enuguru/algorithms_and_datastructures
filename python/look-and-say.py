import itertools
s='1'
def pythonic_solution(s,n):
    for _ in range(n):
        s=''.join(str(len(list(group)))+key for key,group in itertools.groupby(s))
    return s

print(pythonic_solution(s,6))



