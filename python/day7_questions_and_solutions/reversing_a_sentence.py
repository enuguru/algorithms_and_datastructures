def reverse_sentence(s):
    words=s.split(" ")
    words=s[-1::-1]
    sentence=''.join(words)
    print(sentence)

s="Hello Kart"
reverse_sentence(s)
