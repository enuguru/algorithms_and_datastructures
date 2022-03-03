#Program to solve look_and_say problem using pythonic solution
#1,11,21,1211,111221
import itertools
s='1'
def look_and_say(s):
    for _ in range(1,2):
        s=''.join(str(len(list(group))) + key for key,group in itertools.groupby(s))
    return s

print(look_and_say(s))
