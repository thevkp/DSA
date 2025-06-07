#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};


class LinkedList{
    private:
        Node* head;
        Node* tail;
    public:
        LinkedList() : head(nullptr), tail(nullptr) {};
    
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

        Node* getHead(){
            return head;
        }

        Node* getTail(){
            return tail;
        }

        void setHead(Node* newHead){
            head = newHead;
        }

        void setTail(Node* newTail){
            tail = newTail;
        }

        void createNode(int value){
            // creating the Node;
            Node* newNode = new Node(value);

            // if list is not empty
            if(head){
                tail->next = newNode;
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

        Node* deleteAllOccurence(int val) {
            if(!head) return head;

            while(head && head->data == val){
                Node* temp = head;
                head = head->next;
                delete temp;
            }

            Node* prevWalker = nullptr;
            Node* walkerNode = head;

            while(walkerNode)
            {
                if(walkerNode->data == val)
                {
                    prevWalker->next = walkerNode->next;
                    delete walkerNode;
                    walkerNode = prevWalker->next;
                }
                else{
                    prevWalker = walkerNode;
                    walkerNode = walkerNode->next;
                }
            }

            if(prevWalker){
                tail = prevWalker;
            }

            return head;
        }
};


void reverse(LinkedList& list){
    Node* curr = list.getHead();
    Node* prev = nullptr;
    Node* nextNode = nullptr;

    list.setTail(curr);

    while(curr){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    list.setHead(prev);
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

    int val;
    cin >> val;

    list.deleteAllOccurence(val);

   
    reverse(list);
    list.printList();
    list.createNode(6);
    list.printList();


    return 0;
}