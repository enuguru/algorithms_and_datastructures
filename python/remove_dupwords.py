from collections import Counter
def remove_duplicates(s):
    input_str=s.split(" ")
    unique=Counter(input_str)
    s=" ".join(unique.keys())
    print(s)


s="Python is great and Java is also great"
remove_duplicates(s)
