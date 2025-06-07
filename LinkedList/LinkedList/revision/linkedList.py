import os
os.system("cls")


class Node:
    def __init__(self, value: int, next:'Node' = None):
        self.data = value
        self.next = None
        
class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        
    
    def insert(self, value):
        newNode = Node(value)
        
        if self.head is not None:
            self.tail.next = newNode
            self.tail = newNode
        else:
            self.head = newNode
            self.tail = newNode
            
    def print_list(self):
        if self.head is None:
            print("List is empty.")
            return

        walkerNode = self.head
        while walkerNode is not None:
            print(walkerNode.data, end="->")
            walkerNode = walkerNode.next
        print("-1")
        
    def reverse(self):
        if self.head is None or self.head.next is None:
            return
        
        curr = self.head
        prev = None
        nxt = None
        self.tail = self.head
        
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        self.head = prev
    
    def delete_node(self, pos):
        if self.head is None:
            return
        
        if pos == 0:
            self.head = self.head.next
            return
        
            
            
linked_list = LinkedList()

val = int(input())
while val != -1:
    linked_list.insert(val)
    val = int(input())
# linked_list.insert(1)
# linked_list.insert(2)
# linked_list.insert(3)
    
linked_list.print_list()

linked_list.delete_node(0)
linked_list.print_list()

# checking if tail references the last element
# walker_node = linked_list.tail
# while walker_node:
#     print(walker_node.data, end="->")
#     walker_node = walker_node.next
# print("-1")

# reversing the list
# linked_list.reverse()
# linked_list.print_list()

# # checking if tail is being updated to the new tail after reversing
# walker_node = linked_list.tail
# while walker_node:
#     print(walker_node.data, end="->")
#     walker_node = walker_node.next
# print("-1")
