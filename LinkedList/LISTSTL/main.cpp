#include "sll.cpp"
#include <iostream>
using namespace std;


void reverseList(Node*& head, Node*& tail){
    Node* prev = nullptr;
    Node* curr = head;
    Node* nextNode = nullptr;
    
    while(curr){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    head = prev;
    tail = head;
}

void printList(Node* head){
    Node* walkerNode = head;

    while(walkerNode){
        cout << walkerNode->data << " ";
        walkerNode = walkerNode->next;
    }
    cout << endl;
}

int main(){
    system("cls");

    SLL list;

    int input;
    cin >> input;

    while(input != -1){
        list.append(input);
        cin >> input;
    }

    Node* head = list.getHead();
    Node* tail = list.getTail();
    printList(head);
    reverseList(head, tail);
    printList(head);

    return 0;
}