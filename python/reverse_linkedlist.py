class Node:
    def __init__(self,data,next=None):
        self.data=data
        self.next=next

class Linkedlist:
    def __init__(self):
        self.head=None

def add_node(head,data):
    newnode=Node(data)
    if head is None:
        head=newnode
    else:

        n=head
        while n.next is not None:
            n=n.next

        n.next=newnode
    return head

def print_node(l):
    curr=l
    while(curr):
        print(curr.data)
        curr=curr.next

def reverse_list(l):
    prev=None
    curr=l
    while curr:
        temp=curr.next
        curr.next=prev
        prev=curr
        curr=temp

    head=prev
    return head
    


mylist=Linkedlist()
mylist.head=add_node(mylist.head,10)
add_node(mylist.head,20)
add_node(mylist.head,30)
mylist.head=reverse_list(mylist.head)
print_node(mylist.head)



