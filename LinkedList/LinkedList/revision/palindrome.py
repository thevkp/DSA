import os
os.system("cls")

class Node:
    def __init__(self, value):
        self.data = value
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.size = 0
        
    # function to insert nodes
    def insert(self, value):
        #creating a new node
        new_node = Node(value)
        
        # if list is empty, insert the first node
        if self.head is None:
            self.head = new_node
        else:
            walker_node = self.head
            while walker_node.next:
                walker_node = walker_node.next
            walker_node.next = new_node
        
        # Update the size
        self.size += 1
    
    # function to print the list
    def print_list(self):
        if self.head is None:
            print("List is empty.")
            return
        
        walker_node = self.head
        while walker_node:
            print(walker_node.data, end=" -> ")
            walker_node = walker_node.next
        print("-1")
    
    # function to reverse the list from a given node
    def reverse(self, start):
        if start is None or start.next is None:
            return start
        
        curr = start
        prev = None
        nxt = None
        
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        
        return prev

    # function to find the middle element
    def get_mid(self):
        if self.head is None or self.head.next is None:
            return self.head
        
        hare = turtle = self.head
        while hare and hare.next:
            turtle = turtle.next
            hare = hare.next.next
        
        return turtle
    
    # function to check if the list is a palindrome
    def isPalindrome(self):
        if self.head is None or self.head.next is None:
            return True
        
        # Get the middle of the list
        mid = self.get_mid()
        
        # Reverse the second half of the list
        second_half_start = self.reverse(mid)
        
        # Compare the first and second halves
        first_half_iter = self.head
        second_half_iter = second_half_start
        while second_half_iter is not None:
            if first_half_iter.data != second_half_iter.data:
                # Restore the list to its original state before returning
                self.reverse(second_half_start)
                return False
            first_half_iter = first_half_iter.next
            second_half_iter = second_half_iter.next
        
        # Restore the list to its original state
        self.reverse(second_half_start)
        
        return True
    
    def delete_list(self):
        if self.head is None:
            return
        
        walker_node = self.head
        next_node = None
        while walker_node:
            next_node = walker_node.next
            del walker_node
            walker_node = next_node
        
        # self.head = None

# Instantiating the list
linked_list = LinkedList()

val = int(input())
while val != -1:
    linked_list.insert(val)
    val = int(input())

linked_list.print_list()
print(linked_list.isPalindrome())
print(linked_list.get_mid().data)
linked_list.delete_list()
linked_list.print_list()