#include <iostream>
using namespace std;

struct  Node
{                           
    Node* next;
    int data;

    Node(int value) : next(nullptr), data(value) {}
};


class LinkedList
{
    private:
        Node* head;
        Node* tail;
    public:
        LinkedList() : head(nullptr), tail(nullptr) {};
};

int main(){

    return 0;
}