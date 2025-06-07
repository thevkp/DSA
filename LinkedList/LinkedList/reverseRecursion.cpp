#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

class LinkedList{
    private:
        Node* head;
        Node* tail;
    public:
        LinkedList(){
            head = nullptr;
            tail = nullptr;
        }

        void createNode(int value){
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = nullptr;

            if(head != nullptr){
                tail->next = newNode;
                tail = newNode;
            }
            else{
                head = newNode;
                tail = newNode;
            }
        }

        void printList(){
            Node* curr = head;
            while(curr){
                cout << curr->data << " ";
                curr = curr->next;
            }
            cout << endl;
        }

        Node* reverseLinkedList(Node*& head, Node*& prev, Node*& curr, Node*& nextNode){
            if(curr == nullptr)
                return prev;
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        void reverse(){
            Node* curr = head;
            Node* prev = nullptr;
            Node* nextNode = curr->next;

            head = reverseLinkedList(head, prev, curr, nextNode);
        }

        ~LinkedList(){
            Node* curr = head;
            Node* nextNode = nullptr;
            while(curr){
                nextNode = curr->next;
                delete curr;
                curr = nextNode;
            }

            head = nullptr;
            tail = nullptr;
        }
};


int main(){

    

    return 0;
}