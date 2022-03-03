class Word:
    def __init__(self,string,index):
        self.string=string
        self.index=index



def duplicate_array(word,size):
    duplicate=[]
    for i in range(size):
        duplicate.append(Word(word[i],i))
    
    for i in range(size):
        duplicate[i].string=''.join(sorted(duplicate[i].string))
    
    duplicate=sorted(duplicate,key=lambda k:k.string)
    for i in range(size):
        print(word[duplicate[i].index])
    


wordarr=['cat','dog','act','god','tac']
size=len(wordarr)
duplicate_array(wordarr,size)
