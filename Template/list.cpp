#include "sll.cpp"
#include <iostream>
using namespace std;

template <typename T>
Node<T>* reverse(Node<T>* head){
    Node<T>* prev = nullptr;
    Node<T>* curr = head;
    Node<T>* nextNode = nullptr;

    while(curr){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}


int main(){
    // system("cls");

    SLL<int> list;

    int input;
    cin >> input;

    while(input != -1){
        list.append(input);
        cin >> input;
    }

    list.print();


    Node<int>* head = list.getHead();
    Node<int>* newHead = reverse(head);

    list.setHead(newHead);
    list.setTail(head);

    list.print();

    return 0;
}