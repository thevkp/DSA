import os
from collections import deque

os.system("cls")

class Node:
    def __init__(self, value):
        self.left = None
        self.data = value
        self.right = None
    

class BST:
    def __init__(self):
        self.root = None
        
    def insert(self, value):
        new_node = Node(value)
        
        if(new_node.data > value):
            new_node.left = Node(value)
        else:
            new_node.right = Node(value)
        
    def levelorder_traversal(self):
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
            
bst = BST()

val  = int(input())

while val != -1:
    bst.insert(val)
    val = int(input())
    
bst.levelorder_traversal()        
            