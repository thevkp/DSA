#include <iostream>
#include <vector>
#include <cstdlib>
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
            // creating a newNode
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = nullptr;

            // if list is not empty
            if(head){
                tail->next = newNode;
                tail = newNode;
            }
            else{
                head = newNode;
                tail = newNode;
            }
        }


        void printList(){
            if(head == nullptr){
                cout << "List is empty." << endl;
                return;
            }

            Node* walkerNode = head;
            while(walkerNode){
                cout << walkerNode->data << " ";
                walkerNode = walkerNode->next;
            }

            cout << endl;
        }

        Node* getHead(){
            return head;
        }

        void setHead(Node* newHead){
            head = newHead;
        }

        Node* getTail(){
            return tail;
        }

        void setTail(Node* newTail){
            tail = newTail;
        }

        ~LinkedList(){
            Node* walkerNode = head;
            Node* nextNode = nullptr;

            while(walkerNode){
                nextNode = walkerNode->next;
                delete walkerNode;
                walkerNode = nextNode;
            }

            head = nullptr;
            tail = nullptr;
        }
};


vector<Node*> moveLast(Node* head, Node* tail){

    // if list is empty or have single node
    if(!head || !head->next) return {head, tail};

    // traversing to the second-to-last node and last node
    Node* walkerNode = head;
    Node* lastNode = nullptr;
    while(walkerNode->next->next != nullptr){
        walkerNode = walkerNode->next;
    }

    // storing the last node
    lastNode = walkerNode->next;
    walkerNode->next = nullptr;
    tail = walkerNode;

    // linking to the beginning
    lastNode->next = head;
    head = lastNode;

    return {head, tail};
}

int main(){ 
    system("cls");
    LinkedList list;

    int input;
    cin >> input;
    while(input != -1){
        list.createNode(input);
        cin >> input;
    }

    vector<Node*> newHeadTail = moveLast(list.getHead(), list.getTail());
    list.setHead(newHeadTail[0]);
    list.setTail(newHeadTail[1]);
    list.printList();

    list.createNode(7);
    list.printList();

    return 0;
}