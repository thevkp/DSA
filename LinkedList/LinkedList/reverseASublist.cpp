#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class SLL{
    private:
        Node* head;

    public:
        SLL() : head(nullptr) {}

        ~SLL(){
            deleteList();
        }

        void append(int value){
            Node* newNode = new Node(value);

            if(!head){
                head = newNode;
                return;
            }

            Node* walkerNode = head;
            while(walkerNode->next){
                walkerNode = walkerNode->next;
            }

            walkerNode->next = newNode;
        }


        void printList(){
            Node* walkerNode = head;
            while(walkerNode){
                cout << walkerNode->data << " ";
                walkerNode = walkerNode->next;
            }
            cout << endl;
        }

        void deleteList(){
            Node* curr = head;
            Node* nextNode = nullptr;
            while(curr){
                nextNode = curr->next;
                delete curr;
                curr = nextNode;
            }


            head = nullptr;
        }

        Node* getHead(){
            return head;
        }

        void setHead(Node* newHead){
            head = newHead;
        }
};

void reverseSublist(Node*& head, int p, int q){
    if(p == q)
        return;

    Node dummy(0);
    dummy.next = head;

    Node* left = head;
    Node* leftPrev = &dummy;

    for(int i = 1; i < p && left; i++){
        leftPrev = left;
        left = left->next;
    }

    if(!left) return;

    Node* sublistStart = left;
    Node* prev = nullptr;
    Node* nextNode = nullptr;

    for(int i = 0; i <= q - p && left; i++){
        nextNode = left->next;
        left->next = prev;
        prev = left;
        left = nextNode;
    }

    leftPrev->next = prev;
    sublistStart->next = nextNode;

    head = dummy.next;
}
   



int main(){
    system("cls");

    int t;
    cin >> t;



    while(t--){
        SLL list;
        int input;
        cin >> input;

        while(input != -1){
            list.append(input);
            cin >> input;
        }
        int s, e;
        cin >> s >> e;
        Node* head = list.getHead();
        reverseSublist(head, s, e);
        // reverseSublist(head, s, e);
        list.setHead(head);
        list.printList();
    }



    return 0;
}
// 14
// 1 2 3 4 5 -1
// 1 3
// 1 2 3 4 5 -1
// 0 3
// 1 2 3 4 5 -1 
// 0 0
// 1 2 3 4 5 -1 
// 1 1
// 1 2 3 4 5 -1
// 2 3
// 1 2 3 4 5 -1
// 4 5
// 1 2 3 4 5 -1
// 2 5
// 1 2 3 4 5 -1
// 1 5
// 1 2 3 4 5 -1
// 1 2
// 1 2 3 4 5 -1
// 1 4
// 1 2 3 4 5 -1
// 2 4
// 1 2 3 4 5 -1
// 3 4
// 1 2 3 4 5 -1
// 5 5
// 1 2 3 4 5 -1
// 5 6
