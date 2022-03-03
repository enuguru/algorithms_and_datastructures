

class myStack:
     def __init__(self):
         self.container = []  # You don't want to assign [] to self 

     def isEmpty(self):
         return self.size() == 0   # While there's nothing wrong s

     def push(self, item):
         self.container.append(item)  # appending to the *container*, not the instance itself.

     def pop(self):
         return self.container.pop()  # pop from the container, this was fixed from the old version

     def size(self):
         return len(self.container)  # length of the container

s = myStack()
s.push('1')
s.push('2')
print(s.pop())
print(s.pop())
print(s)
