
class Node:
    
    # Constructor to initialize data
    # If data is not given by user,its taken as None 
    def __init__(self, data=None, next=None, prev=None):
        self.data = data
        self.next = next
        self.prev = prev

    # __str__ returns string equivalent of Object
    def __str__(self):
        return "Node[Data = %s]" % (self.data,)

class DoubleLinkedList:
    
    def __init__(self):
        self.head = None
        self.tail = None
    
    def insert(self, data):
        if (self.head == None): # To imply that if head == None
            self.head = Node(data)
            self.tail = self.head
        else:
            current = self.head
            while(current.next != None):
                current = current.next
            current.next = Node(data, None, current)
            self.tail = current.next

    def delete(self, data):
        current = self.head
        # If given item is the first element of the linked list
        if current.data == data:
            self.head = current.next
            self.head.prev = None
            return True
        
        # In case the linked list is empty
        if current == None:
            return False

        # If the element is at the last
        if self.tail == data:
            self.tail = self.tail.prev
            self.tail.next = None
            return True

        # If the element is absent or in the middle of the linked list
        while current != None:
            if current.data == data :
                current.prev.next = current.next
                current.next.prev = current.prev
                return True
            current = current.next
     
        # The element is absent
        return False

    def find(self, data):
        current = self.head
        while current != None:
            if current.data == data :
                return True
            current = current.next
        return False

    def fwd_print(self):
        current = self.head
        if current == None:
            print("No elements")
            return False
        while (current!= None):
            print (current.data) 
            current = current.next
        return True

    def rev_print(self):
        current = self.tail
        if (self.tail == None):
            print("No elements")
            return False

        while (current != None):
            print (current.data)
            current = current.prev
        return True

# Initializing list
l = DoubleLinkedList()

# Inserting Values
l.insert(1)
l.insert(2)
l.insert(3)
l.insert(4)

# Forward Print
l.fwd_print()

# Reverse Print
l.rev_print()

# Try to find 3 in the list
if (l.find(3)):
    print("Found")
else :
    print("Not found")

# Delete 3 from the list
l.delete(3)

# Forward Print
l.fwd_print()

# Reverse Print
l.rev_print()

# Now if we find 3, we will not get it in the list
if (l.find(3)):
    print("Found")
else :
    print("Not found")
