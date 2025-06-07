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

        void reorderEvenOdd(){
            if(!head || !head->next) return;

            Node* evenHead = nullptr;
            Node* oddHead = nullptr;
            Node* evenTail = nullptr;
            Node* oddTail = nullptr;

            Node* walkerNode = head;
            while(walkerNode){
                Node* nextNode = walkerNode->next;
                walkerNode->next = nullptr;

                if(walkerNode->data % 2 == 0){
                    if(evenHead){
                        evenTail->next = walkerNode;
                        evenTail = walkerNode;
                    }
                    else{
                        evenHead = evenTail = walkerNode;
                    }
                }
                else{
                    if(oddHead){
                        oddTail->next = walkerNode;
                        oddTail = walkerNode;
                    }
                    else{
                        oddHead = oddTail = walkerNode;
                    }
                }

                walkerNode = nextNode;
            }


            if(evenTail){
                evenTail->next = oddHead;
                head = evenHead;
            }
            else{
                head = oddHead;
            }

            tail = oddTail ? oddTail : evenTail;
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
    list.reorderEvenOdd();
    list.printList();




    return 0;
}


// 17 15 8 12 10 5 4 1 7 6 -1