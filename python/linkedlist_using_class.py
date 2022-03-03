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

    def print_node(self):
        curr=self.head
        while(curr):
            print(curr.data)
            curr=curr.next

    def merge_sorted_list(self,l1,l2):
        tail=dummy_head=Linkedlist()
        while l1 and l2:
            if l1.data<l2.data:
                tail.next,l1=l1,l1.next
            else:
                tail.next,l2=l2,l2.next
            
            tail=tail.next

        tail.next=l1 or l2
        return dummy_head.next

mylist=Linkedlist()
mylist.add_node(5)
mylist.add_node(10)
slist=Linkedlist()
slist.add_node(4)
slist.add_node(8)
#slist.print_node()
tlist=Linkedlist()
tlist.head=tlist.merge_sorted_list(mylist.head,slist.head)
tlist.print_node()
