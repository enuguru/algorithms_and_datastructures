class Node:
    def __init__(self,data,next=None):
        self.data=data
        self.next=next

class Linkedlist:
    def __init__(self):
        self.head=None

    def add_node(self,data):
        newnode=Node(data)
        if self.head is None:
            self.head=newnode

        else:
            n=self.head
            while n.next is not None:
                n=n.next
            n.next=newnode

def print_node(l):
    curr=l
    while(curr):
        print(curr.data)
        curr=curr.next

def reverse_list(l):
    prev=None
    curr=l
    while(curr):
        temp=curr.next
        curr.next=prev
        prev=curr
        curr=temp
    head=prev
    return head

def palindrome_list(l1):
    slow=fast=l1
    while fast and fast.next:
        slow,fast=slow.next,fast.next.next

    first_iter,second_iter=l1,reverse_list(slow)
    while first_iter and second_iter:
        if second_iter.data!=first_iter.data:
            return False
        second_iter,first_iter=second_iter.next,first_iter.next

    return True

mylist=Linkedlist()
mylist.add_node(3)
mylist.add_node(4)
mylist.add_node(4)
mylist.add_node(3)
print(palindrome_list(mylist.head))
