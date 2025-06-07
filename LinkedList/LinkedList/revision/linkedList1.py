import os
os.system("cls")

class Node:
    def __init__(self, value):
        self.data = value
        self.next = None
        
class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0
    
    # function to insert nodes at the end
    def insert(self, value):
        #creating a node
        new_node = Node(value)
        
        if self.head is not None:
            self.tail.next = new_node
            self.tail = new_node
            self.size += 1
        else:
            self.head = new_node
            self.tail = new_node
            self.size += 1
       
    # function to delete node at a specified position 
    def delete_node(self, pos):
        # if list is empty, nothing to delete
        if self.head is None:
            return
        
        # if node to be delete is head, i.e. position is 0
        if pos == 0:
            self.head = self.head.next
            self.size -= 1
            return
        
        # if head was the only element, update the tail
        if self.head is None:
            self.tail = None
            return
            
        # traversing to the specified node 
        walker_node = self.head
        prev_node = None
        
        i = 0
        while i < pos and walker_node is not None:
            prev_node = walker_node
            walker_node = walker_node.next
            i += 1
        
        
        # if the position is out of bound walker_node will be None
        if walker_node is None:
            print("Position out of bound")
            return 

        # finally remove the specified node
        prev_node.next = walker_node.next
        self.size -= 1
        
        # if the node to be deleted is tail, update the tail
        if walker_node.next is None:
            self.tail = prev_node
           
    # function to print list 
    def print_list(self):
        if self.head is None:
            print("List is empty.")
            return
        
        walker_node = self.head
        while walker_node:
            print(walker_node.data, end="->")
            walker_node = walker_node.next
        print("-1")
        
        
# instantiating the LinkedList class 
linked_list = LinkedList()

# taking inputs and inserting them to the list
val = int(input())
while val != -1:
    linked_list.insert(val)
    val = int(input())
    

linked_list.print_list()
print(f"Size: {linked_list.size}")

index = int(input())
linked_list.delete_node(index)
linked_list.print_list()
print(f"Size: {linked_list.size}")