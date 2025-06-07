#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {};
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
    public:
        LinkedList() : head(nullptr), tail(nullptr) {};

        ~LinkedList() {
            deleteList();
        }

        void insert(int value){
            // creating a new node
            Node* newNode = new Node(value);

            if(head){
                tail->next = newNode;
                tail = newNode;
            }
            else {
                head = tail = newNode;
            }
        }

        void printList(){
            if(head == nullptr) {
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
            if(head == nullptr) return;

            Node* walkerNode = head;
            Node* nextNode = nullptr;
            while(walkerNode){
                nextNode = walkerNode->next;
                delete walkerNode;
                walkerNode = nextNode;
            }

            head = tail = nullptr;
        }

        Node* getMid(){
            if(head == nullptr || head->next == nullptr)
                return head;

            Node* slow = head;
            Node* slowFollower = slow;
            Node* fast = head;

            while(fast->next != nullptr && fast->next->next != nullptr){
                slowFollower = slow;
                slow = slow->next;
                fast = fast->next->next;
            }

            return slowFollower;
        }
};

int main(){
    system("cls");

    LinkedList list;
    int input;
    cin >> input;

    while(input != -1){
        list.insert(input);
        cin >> input;
    }

    list.printList();
    cout << list.getMid()->data << endl;

    return 0;
}