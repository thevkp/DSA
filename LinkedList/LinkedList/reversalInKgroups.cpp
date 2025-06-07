#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};


class LinkedList{
    private:
        Node* head;
    public:
        LinkedList() : head(nullptr){}

        void creatNode(int value){
            // creating the Node;
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = nullptr;

            // if list is empty
            if(!head){
                head = newNode;
                return;
            }

            Node* walkerNode = head;
            while(walkerNode->next){
                walkerNode = walkerNode->next;
            }

            // linking to the end;
            walkerNode->next = newNode;
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
        
        Node* getHead(){
            return head;
        }

        void setHead(Node* newHead){
            head = newHead;
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
        }
};

Node* reverse(Node* head, int k){
    if(head == nullptr) return nullptr;

    //reverse first k groups;
    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    int count = 0;

    while(curr != nullptr && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != nullptr){
        head->next = reverse(next, k);
    }

    return prev;
}

int  main(){
    system("cls");
    LinkedList list;

    int input, k;
    cin >> input;
    while(input != -1){
        list.creatNode(input);
        cin >> input;
    }

    cin >> k;
    // list.printList();
    Node* newHead = reverse(list.getHead(), k);
    list.setHead(newHead);

    list.printList();

    return 0;
}