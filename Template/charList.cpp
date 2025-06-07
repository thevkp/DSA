#include "sll.cpp"
#include <iostream>
using namespace std;

template <typename T>
Node<T>* reverse(Node<T>* head){
    Node<T>* prev = nullptr;
    Node<T>* curr = head;
    Node<T>* next = nullptr;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main(){
    SLL<char> list;


    char input;

    while(cin >> input && input != '0'){
        list.append(input);
    }

    list.print();

    Node<char>* head = list.getHead();
    Node<char>* newHead = reverse(head);

    list.setHead(newHead);
    list.setTail(head);

    list.print();
    list.append('f');
    list.print();




    return 0;
}