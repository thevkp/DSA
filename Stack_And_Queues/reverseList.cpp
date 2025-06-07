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
        int listSize;

    public:
        SLL(){
            head = nullptr;
            listSize = 0;
        }

        ~SLL(){
            deleteList();
        }

        void addToList(int value){
            Node* newNode = new Node(value);

            newNode->next = head;
            head = newNode;
            listSize = listSize + 1;
        }

        int size(){
            return listSize;
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

        void reverseList(){
            Node* curr = head;
            Node* prev = nullptr;
            Node* nxt = nullptr;

            while(curr){
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }

            head = prev;
        }

        void deleteList(){
            Node* current = head;
            Node* nextNode = nullptr;

            while(current){
                nextNode = current->next;
                delete current;
                current = nextNode;
            }

            head = nullptr;
        }
};

int main(){
    system("cls");

    SLL list;

    int input;
    cin >> input;

    while(input != -1){
        list.addToList(input);
        cin >> input;
    }

    list.printList();
    // list.deleteList();
    // list.printList();

    list.reverseList();
    list.printList();
    cout << list.size() << endl;

    return 0;
}