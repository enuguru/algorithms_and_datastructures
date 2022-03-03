class Node:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None

    def add_node(self,data):
        if root.data>data:
            if root.left is None:
                root.left=Node(data)
            else:
                add_node(root.left,data)

        elif root.data<data:
            if root.right is None:
                root.right=Node(data)
            else:
                add_node(root.right,data)
        
        return root
    
def inorder(root):
    if root:
        inorder(root.left)
        print(root.data)
        inorder(root.right)



root=Node(10)
root.add_node(12)
root.add_node(9)
inorder(root)



