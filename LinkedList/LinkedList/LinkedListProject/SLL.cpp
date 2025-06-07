#include "SLL.h"
#include <iostream>
using namespace std;


Node::Node(int value) : data(value), next(nullptr) {}

SLL::SLL() : head(nullptr), tail(nullptr), listLength(0) {}

SLL::~SLL() { deleteList(); }

void SLL::append(int value){
    Node* newNode = new Node(value);
    
    if(head){
        tail->next = newNode;
        tail = newNode;
        listLength++;
    }
    else{
        head = tail = newNode;
        listLength++;
    }
}

void SLL::printList(){
    Node* walkerNode = head;
    while(walkerNode){
        cout << walkerNode->data << " ";
        walkerNode = walkerNode->next;
    }
    cout << endl;
}

const int SLL::length() const{
    return listLength;
}

void SLL::reverseList(){
    Node* prev = nullptr;
    Node* curr = head;
    Node* nextNode = nullptr;

    while(curr){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    tail = head;
    head = prev;
}

void SLL::deleteList(){
    Node* curr = head;
    Node* nextNode = nullptr;

    while(curr){
        nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }

    head = tail = nullptr;
    listLength = 0;
}

Node* SLL::getHead() const{
    return head;
}

int SLL::sumNLastNodes(int n){
    if(!head) return -1;
    if(!head->next) return head->data;

    Node* turtle = head;
    Node* hare = head;

    for(int i = 1; i < n && hare; i++){
        hare = hare->next;
    }

    if(!hare) return -1;

    while(hare->next){
        turtle = turtle->next;
        hare = hare->next;
    }

    int sum = 0;
    while(turtle){
        sum += turtle->data;
        turtle = turtle->next;
    }

    return sum;
}