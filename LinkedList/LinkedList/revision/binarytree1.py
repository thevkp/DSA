import os
from collections import deque
os.system("cls")

class Node:
    def __init__(self, value):
        self.data = value
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    # Function to build the tree from user input
    def build_tree(self):
        val = int(input())
        
        # Base case: if the input is -1, return None (no node)
        if val == -1:
            return None
        
        # Create the parent node
        parent = Node(val)
        
        parent.left = self.build_tree()  # Recursively build the left subtree
        
        parent.right = self.build_tree()  # Recursively build the right subtree
        
        return parent
    
    # Function for inorder traversal of the tree
    def inorder_traversal(self, root):
        if root is None:
            return
        
        self.inorder_traversal(root.left)  # Traverse the left subtree
        print(root.data, end=" ")          # Visit the root
        self.inorder_traversal(root.right) # Traverse the right subtree
    
    # function to leveleorder traversal
    def levelorder_traversal(self):
        if self.root is None:
            print("Tree is empty.")
            return
        
        q = deque([self.root])
        
        while q:
            levelSize = len(q)
            
            for i in range(levelSize):
                curr = q.popleft()
                
                print(curr.data, end=" ")
                
                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)
            print()

# Instantiating the binary tree
tree = BinaryTree()

tree.root = tree.build_tree()  # Build the tree and assign it to the root

tree.inorder_traversal(tree.root)  # Perform inorder traversal
print()
tree.levelorder_traversal() 