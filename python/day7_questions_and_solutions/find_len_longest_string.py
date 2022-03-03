
def find_longest_string(words_list):
    word_len = []
    for n in words_list:
        word_len.append((len(n), n))
    word_len.sort()
    return word_len

mylist = find_longest_string(["Python", "Java", "Scala"])
print(mylist[-1][0], mylist[-1][1])


def longest_word(mylist):
    return sorted(mylist, key=len)

newlist=longest_word(['dinner', 'tasty', 'delicious', 'hot'])
print(len(newlist[-1]), newlist[-1])
