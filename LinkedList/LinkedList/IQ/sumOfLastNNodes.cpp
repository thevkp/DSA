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


};

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




    return 0;
}

//1 -2 -3 -4 -5 -1
