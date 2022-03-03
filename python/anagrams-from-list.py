class Word:
    def __init__(self,array,index):
        self.array=array
        self.index=index

def create_duplicate_array(wordArr,size):
    duplicate_array=[]
    for i in range(size):
        duplicate_array.append(Word(wordArr[i],i))

    return duplicate_array

def print_anagrams(wordArr,size):
    dup_array=create_duplicate_array(wordArr,size)
    for i in range(size):
        dup_array[i].array=''.join(sorted(dup_array[i].array))

    dup_array=sorted(dup_array,key=lambda k:k.array)

    for word in dup_array:
        print(wordArr[word.index])




wordArr = ["cat", "dog", "tac", "god", "act"]
size=len(wordArr)
print_anagrams(wordArr,size)

