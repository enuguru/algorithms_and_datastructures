class Node:
    def __init__(self,data):
        self.data=data
        self.next=None


class Linkedlist:
    def __init__(self,head=None):
        self.head=head

    def add_node(self,data):
        newnode=Node(data)
        if not self.head:
            self.head=newnode

        else:
            curr=self.head
            while curr.next:
                curr=curr.next
            curr.next=newnode

    def print_node(self):
        curr=self.head
        while curr:
            print(curr.data)
            curr=curr.next


mylist=Linkedlist()
mylist.add_node(1)
mylist.add_node(10)
mylist.add_node(12)
mylist.print_node()

