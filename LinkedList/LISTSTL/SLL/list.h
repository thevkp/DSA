#ifndef SLL_H
#define SLL_H

#include <iostream>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node<T>* next;

    Node(T value);
};

template <typename T>
class SLL{
    private:
        Node<T>* head;
        Node<T>* tail;
        size_t listSize;
    public:
        SLL();
        ~SLL();

        void append(T value);
        void print();
        void clear();
        
        Node<T>* getHead();
        Node<T>* getTail();

        void setHead(Node<T>* newHead);
        void setTail(Node<T>* newTail);
        void reverse();

        // template <typename T>
        class Iterator{
            private:
                Node<T>* current;
            public:
                Iterator(Node<T>* node) : current(node) {}

                T& operator*() const { return current->data; }

                Iterator& operator++(){
                    if(current) current = current->next;
                    return *this;
                }

                bool operator==(const Iterator& other) const {
                    return current == other.current;
                }

                bool operator!=(const Iterator& other) const {    
                    return !(*this == other);
                }  
        };
        Iterator begin() const { return Iterator(head); }
        Iterator end() const { return Iterator(nullptr); }
};

template <typename T>
Node<T>::Node(T value): data(value), next(nullptr) {}

template <typename T>
SLL<T>::SLL() : head(nullptr), tail(nullptr), listSize(0) {}

template <typename T>
SLL<T>::~SLL() { clear(); }

template <typename T>
void SLL<T>::append(T value){
    Node<T>* newNode = new Node(value);

    if(head){
        tail->next = newNode;
        tail = newNode;
    }
    else{
        head = tail = newNode;
    }
    ++listSize;
}

template <typename T>
void SLL<T>::print(){
    Node<T>* walkerNode = head;
    
    while(walkerNode){
        cout << walkerNode->data << " ";
        walkerNode = walkerNode->next;
    }
    cout << "NULL\n";
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
    listSize = 0;
}

template <typename T>
void SLL<T>::reverse(){
    Node<T>* prev = nullptr;
    Node<T>* curr = head;
    Node<T>* next = nullptr;

    tail = head;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

#endif