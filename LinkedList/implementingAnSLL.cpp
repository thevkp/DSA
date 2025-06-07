#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class SLL{
    private:
        Node* head, *tail;
    public:
        SLL() {
            head = tail = nullptr;
        }

        ~SLL(){
            deleteList();
        }

        void createNode(int value){
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
            if(head == nullptr){
                cout << "List is empty." << endl;
                return;
            }
            
            Node* walkerNode = head;
            while(walkerNode){
                cout << walkerNode->data << "->";
                walkerNode = walkerNode->next;
            }
            cout << "-1" << endl;
        }

        void deleteList(){
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
    SLL list;

    int input;
    cin >> input;
    while(input != -1){
        list.createNode(input);
        cin >> input;
    }

    list.printList();
    list.deleteList();
    list.printList();


    return 0;
}