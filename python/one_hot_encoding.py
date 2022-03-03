from numpy import argmax
data = 'hello world'
print(data)
alphabet = 'abcdefghijklmnopqrstuvwxyz '
char_to_int = dict((c, i) for i, c in enumerate(alphabet))
int_to_char = dict((i, c) for i, c in enumerate(alphabet))
integer_encoded = [char_to_int[char] for char in data]
print(integer_encoded)
onehot_encoded = list()
for value in integer_encoded:
	letter = [0 for _ in range(len(alphabet))]
	letter[value] = 1
	onehot_encoded.append(letter)
print(onehot_encoded)
inverted = int_to_char[argmax(onehot_encoded[0])]
print(inverted)
