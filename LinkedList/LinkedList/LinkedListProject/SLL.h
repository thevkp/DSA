#ifndef SLL_H
#define SLL_H

struct Node{
    int data;
    Node* next;

    Node(int value);
};


class SLL{
    private:
        Node* head;
        Node* tail;
        int listLength;
    public:
        SLL();
        ~SLL();

        void append(int value);
        void printList();
        void deleteList();
        void reverseList();
        int sumNLastNodes(int n);
        Node* getHead() const;
        const int length() const;
};

#endif