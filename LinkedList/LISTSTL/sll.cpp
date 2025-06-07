#include "sll.h"
#include <iostream>
using namespace std;


Node::Node(int value) : data(value), next(nullptr) {}

SLL::SLL() : head(nullptr), tail(nullptr) {}

SLL::~SLL(){ deleteList(); }

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

void SLL::print(){
    Node* walkerNode = head;
    
    while(walkerNode){
        cout << walkerNode->data << " ";
        walkerNode = walkerNode->next;
    }
    cout << endl;
}

void SLL::deleteList(){
    Node* curr = head;
    Node* nextNode = nullptr;

    while(curr){
        nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }

    listLength = 0;
}

void SLL::pop_front(){
    if(!head) return;

    Node* temp = head;
    head = head->next;
    delete temp;
    listLength--;

    if(!head) tail = nullptr;
}

Node* SLL::getHead(){
    return head;
}

Node* SLL::getTail(){
    return tail;c
}


void SLL::clear(){
    deleteList();
}

int SLL::front(){
    return head ? head->data : -1;
}

int SLL::back(){
    return tail ? tail->data : -1;
}

bool SLL::empty(){
    return listLength == 0 || head == nullptr || tail == nullptr;
}

int SLL::size(){
    return listLength;
}

int SLL::length(){
    return listLength;
}












// int SLL::front() const {
//     return head ? head->data : throw std::runtime_error("List is empty");
// }

// int SLL::back() const {
//     return tail ? tail->data : throw std::runtime_error("List is empty");
// }

// bool SLL::empty() const {
//     return head == nullptr;
// }

// int SLL::size() const {
//     int count = 0;
//     for(Node* curr = head; curr; curr = curr->next) count++;
//     return count;
// }

// void SLL::clear() {
//     deleteList();  // same implementation
// }

