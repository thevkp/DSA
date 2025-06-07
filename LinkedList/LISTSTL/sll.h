#ifndef sll_h
#define sll

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
        void deleteList();
    public:
        SLL();
        ~SLL();

        void append(int value);
        void print();
        void clear();
        void pop_front();

        int length();

        Node* getHead();
        Node* getTail();

        int front();
        int back();
        bool empty();
        int size();
};

#endif