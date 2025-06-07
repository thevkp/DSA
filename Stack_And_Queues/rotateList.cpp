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
            ++listSize;
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

        void reverseList(){
            Node* prev = nullptr;
            Node* curr = head;
            Node* nextNode = nullptr;

            while(curr){
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            head = prev;
        }


        void reverseFirstKNodes(int k){
            if(!head){
                cout << "List is empty." << endl;
                return;
            }

            if(k == 1){
                return;
            }

            Node* prev = nullptr;
            Node* curr = head;
            Node* nextNode = nullptr;
            // Node* newHead = head;

            while(curr && k){
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
                k--;
            }

            // newHead->next = curr;
            head->next = curr;
            head = prev;
        }

        void reverseLastPart(int k){
            Node* walkerNode = head;
            int count = 0;

            while(walkerNode && count < k){
                walkerNode = walkerNode->next;
                count++;
            }

            cout << walkerNode->data << endl;
        }

        void rotateList(int k){
            k = k % listSize;

            reverseFirstKNodes(listSize - k);
            reverseFirstKNodes(listSize);
            reverseFirstKNodes(k);
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

    // list.printList();
    list.reverseList();
    list.printList();
    // list.reverseFirstKNodes(5);
    // list.printList();

    list.rotateList(2);
    list.printList();





    return 0;
}