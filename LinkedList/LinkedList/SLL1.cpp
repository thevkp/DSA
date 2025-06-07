#include <iostream>
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

        void printHead(){
            cout << head << endl;
        }
        void printTail(){
            cout << tail << endl;
        }

        void createNode(int value){
            Node* temp = new Node();
            temp->data = value;
            temp->next = nullptr;

            if(head == nullptr){
                head = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                tail = temp;
            }
        }

        int pop(){
            if(head == nullptr){
                cout << "List is empty." << endl;
                return -1;
            }

            int poppedVal = head->data;

            Node* firstNode = head;
            head = head->next;
            delete firstNode;
        
            return poppedVal;
        }

        void removeLast(){
            if(head == nullptr){
                cout << "List is empty." << endl;
            }
            else if(head->next == nullptr){
                delete head;
                head = nullptr;
            }
            else{
                Node* secondLast = head;

                while(secondLast->next->next != nullptr){
                    secondLast = secondLast->next;
                }

                delete secondLast->next;
                secondLast->next = nullptr;

                tail = secondLast;
            }
        }

        void printList(){
            Node* current = head;

            if(current == nullptr){
                cout << "List is empty." << endl;
                return;
            }

            while(current != nullptr){
                cout << current->data << " ";
                current = current->next;
            }
            cout << "\n";
        }


        ~LinkedList(){
            Node* current = head;
            Node* nextNode;
            while(current != nullptr){
                nextNode = current->next;
                delete current;
                current = nextNode;
            }
            
            head = nullptr;
            tail = nullptr;
        }
};

int main(){
    LinkedList list;
    // list.printHead();
    // list.printTail();
    // list.printList();


    list.createNode(1);
    list.createNode(2);
    list.createNode(3);
    list.createNode(4);

    list.printList();

    // list.printHead();
    // list.printTail();


    return 0;
}