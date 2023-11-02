class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def serialize(root):
    def preorder(node):
        if node:
            vals.append(str(node.val))
            preorder(node.left)
            preorder(node.right)
        else:
            vals.append('#')
    vals = []
    preorder(root)
    return ' '.join(vals)

def deserialize(data):
    def build():
        val = next(vals)
        if val == '#':
            return None
        node = TreeNode(int(val))
        node.left = build()
        node.right = build()
        return node
    vals = iter(data.split())
    return build()

# Test
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.right.left = TreeNode(4)
root.right.right = TreeNode(5)

data = serialize(root)
print(data)  # Output: '1 2 # # 3 4 # # 5 # #'

new_root = deserialize(data)
print(serialize(new_root))  # Output: '1 2 # # 3 4 # # 5 # #'
