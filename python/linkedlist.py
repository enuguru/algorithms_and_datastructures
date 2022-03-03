class Node:
    def __init__(self,data,next=None):
        self.data=data
        self.next=next
    

class Linkedlist:
    def __init__(self):
        self.head=None

    def addnode(self,data):
        newnode=Node(data)
        if self.head is None:
            self.head=newnode
        else:
            n=self.head
            while n.next is not None:
                n=n.next
            n.next=newnode

    def printnode(self):
        curr=self.head
        while curr:
            print(curr.data)
            curr=curr.next

    def cyclic_right_shift(self,k):
        tail=self.head
        n=1
        while(tail.next):
            tail=tail.next
            n=n+1

        tail.next=self.head

        new_head_count,new_tail=n-k,tail
        while new_head_count:
            new_head_count-=1
            new_tail=new_tail.next

        new_head=new_tail.next
        new_tail.next=None
        return new_head





mylist=Linkedlist()
modylist=Linkedlist()
mylist.addnode(2)
mylist.addnode(3)
mylist.addnode(5)
mylist.addnode(3)
mylist.addnode(2)
modylist.head=mylist.cyclic_right_shift(3)
modylist.printnode()

