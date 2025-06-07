#include "sll.h"
#include <iostream>
using namespace std;

template <typename T>
Node<T>::Node(T value) : data(value), next(nullptr) {}


template <typename T>
SLL<T>::SLL() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
SLL<T>::~SLL(){ clear(); }


template <typename T>
void SLL<T>::append(T val){
    Node<T>* newNode = new Node<T>(val);

    if(head){
        tail->next = newNode;
        tail = newNode;
    }
    else{
        head = tail = newNode;
    }
    ++size;
}


template <typename T>
void SLL<T>::print(){
    Node<T>* walkerNode = head;
    while(walkerNode){
        cout << walkerNode->data << " ";
        walkerNode = walkerNode->next;
    }
    cout << endl;
}


template <typename T>
void SLL<T>::clear(){
    Node<T>* curr = head;
    Node<T>* nextNode = nullptr;

    while(curr){
        nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }

    head = tail = nullptr;
    size = 0;
}

template <typename T>
Node<T>* SLL<T>::getHead(){
    return head;
}

template <typename T>
void SLL<T>::setHead(Node<T>* newHead){
    head = newHead;
}

template <typename T>
void SLL<T>::setTail(Node<T>* newTail){
    tail = newTail;
}
