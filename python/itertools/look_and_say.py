import itertools
s='11111'
for key,group in itertools.groupby(s):
    print(type(key))
    print(str(len(list(group)))+key)

