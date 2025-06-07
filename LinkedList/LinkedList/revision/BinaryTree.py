import os
os.system("cls")

class Node:
    def __init__(self, value):
        self.data = value
        self.left = None
        self.right = None
        
class binary_tree:
    def __init__(self):
        self.root = None
    
    def build_tree(self):
        val = int(input())
        
        if val == -1:
            return None
        
        parent = Node(val)
        
        parent.left = self.build_tree()
        parent.right = self.build_tree()
        
        return parent
    
    def inorder_traversal(self, root):
        if root is None:
            return
        
        self.inorder_traversal(root.left)
        print(root.data, end=" ")
        self.inorder_traversal(root.right)
        
        
tree = binary_tree()

val = int(input())

tree.root = tree.build_tree()
    
tree.inorder_traversal(tree.root)