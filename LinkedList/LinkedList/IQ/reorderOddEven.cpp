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
        Node* tail;
    public:
        SLL() : head(nullptr), tail(nullptr) {}
        ~SLL() { deleteList(); }


        void append(int value){
            Node* newNode = new Node(value);

            if(head){
                tail->next = newNode;
                tail = newNode;
            }
            else{
                head = tail = newNode;
            }
        }

        void printList(){
            Node* walkerNode = head;

            while(walkerNode){
                cout << walkerNode->data << " ";
                walkerNode = walkerNode->next;
            }
            cout << "\n";
        }

        void deleteList(){
            Node* curr = head;
            Node* nextNode = nullptr;

            while(curr){
                nextNode = curr->next;
                delete curr;
                curr = nextNode;
            }

            head = tail = nullptr;
        }

        Node* reorderEvenOdd(){
            Node* evenList = new Node(0);
            Node* oddList = new Node(0);

            Node* evenStart = evenList;
            Node* oddStart = oddList;
            Node* evenEnd = evenList;
            Node* oddEnd = oddList;

            Node* walkerNode = head;
            while(walkerNode){
                int nodeVal = walkerNode->data;
                if(nodeVal % 2){
                    oddEnd->next = new Node(nodeVal);
                    oddEnd = oddEnd->next;
                }
                else{
                    evenEnd->next = new Node(nodeVal);
                    evenEnd = evenEnd->next;
                }
                walkerNode = walkerNode->next;
            }

            evenEnd->next = oddStart->next;

            return evenStart->next;
        }
};


void printList(Node* head){
    Node* walkerNode = head;
    while(walkerNode){
        cout << walkerNode->data << " ";
        walkerNode = walkerNode->next;
    }
    cout << endl;
}


int main(){
    system("cls");

    SLL list;

    int input;
    cin >> input;

    while(input != -1){
        list.append(input);
        cin >> input;
    }

    list.printList();
    Node* node = list.reorderEvenOdd();
    printList(node);




    return 0;
}


// 17 15 8 12 10 5 4 1 7 6 -1