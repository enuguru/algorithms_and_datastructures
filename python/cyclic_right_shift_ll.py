class Node:
    def __init__(self,data,next=None):
        self.data=data
        self.next=None

class Linkedlist:
    def __init__(self):
        self.head=None


def add_node(data,head):
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
    while curr:
        print(curr.data)
        curr=curr.next

def cyclic_rightshift(l,k):
    if l is None:
        return l
    tail,n=l,1
    while tail.next is not None:
        tail=tail.next
        n+=1
    tail.next=l
    
    k=k%n
    if k==0:
        return l
    new_head_count,new_tail=n-k,tail

    while new_head_count:
        new_tail=new_tail.next
        new_head_count-=1;

    new_head=new_tail.next
    new_tail.next=None
    return new_head


mylist=Linkedlist()
mylist.head=add_node(2,mylist.head)
add_node(3,mylist.head)
add_node(5,mylist.head)
add_node(3,mylist.head)
add_node(2,mylist.head)
mylist.head=cyclic_rightshift(mylist.head,3)
print_node(mylist.head)
