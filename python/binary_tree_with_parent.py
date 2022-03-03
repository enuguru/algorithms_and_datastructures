class Node:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None
        self.parent=None


def insert_data(root,data):
    if root.data>data:
        if root.left is None:
            root.left=Node(data)
            root.left.parent=root
        else:
            insert_data(root.left,data)

    elif root.data<data:
        if root.right is None:
            root.right=Node(data)
            root.right.parent=root

        else:
            insert_data(root.right,data)

    return root

def print_data(root):
    curr=root
    if root:
        print_data(root.left)
        print(root.data)
        print_data(root.right)


root=Node(10)
insert_data(root,9)
insert_data(root,8)
insert_data(root,11)




