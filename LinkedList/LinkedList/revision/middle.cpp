#include <iostream>
using namespace std;


class SLL{
    private:
        struct Node{
            int data;
            Node* next;


            Node(int value) : data(value), next(nullptr) {}
        };

        Node* head;
        Node* tail;
    public:
        SLL(){
            head = tail = nullptr;
        }

        ~SLL(){
            deleteList();
        }

        void insert(int value){
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
            if(!head){
                cout << "List is empty" << endl;
                return;
            }

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

            head = tail = nullptr;
        }

        int middle(){
            if(!head){
                return -1;
            }
            Node* turtle = head;
            Node* hare = head;

            while(hare != nullptr && hare->next != nullptr){
                turtle = turtle->next;
                hare = hare->next->next;
            }

            return turtle->data;
        }

};



int main(){
    system("cls");

    SLL list;

    int input;
    cin >> input;

    while(input != -1){
        list.insert(input);
        cin >> input;
    }

    list.printList();

    cout << list.middle() << endl;



    return 0;
}