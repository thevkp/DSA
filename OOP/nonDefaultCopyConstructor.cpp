#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}; 
};

class LinkedList{
    private:
        Node* head;
        Node* tail;
    public:
        LinkedList() : head(nullptr), tail(nullptr) {}

        // copy constructor
        LinkedList(const LinkedList& nodeRef): head(nullptr), tail(nullptr) {
            Node* current = nodeRef.head;
            while(current != nullptr){
                createNode(current->data);
                current = current->next;
            }
        }

        void createNode(int value){
            // creating the node
            Node* newNode = new Node(value);

            // if list is not empty add to end
            if(head){
                tail->next =  newNode;
                tail = newNode;
            }
            else{
                head = tail = newNode;
            }
        }

        void printList(){
            if(!head){
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
        ~LinkedList(){
            Node* walkerNode = head;
            Node* nextNode = nullptr;
            while(walkerNode){
                nextNode = walkerNode->next;
                delete walkerNode;
                walkerNode = nextNode;
            }

            head = tail = nullptr;
        }
};


int main(){
    system("cls");
    LinkedList list1;
    
    int input;
    cin >> input;
    while(input != -1){
        list1.createNode(input);
        cin >> input;
    }

    list1.printList();

    LinkedList list2(list1);
    list2.printList();

    return 0;
}