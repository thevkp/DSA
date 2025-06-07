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


        void deleteList() {
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
            Node* slow = head;
            Node* fast = head;

            while(fast->next && fast->next->next){
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow;
        }

        Node* rev(Node* node){
            Node* curr = node;          
            Node* prev = nullptr;
            Node* nextNode = nullptr;

            while(curr){
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            return prev;
        }

        // twin sum
        int twinSum(){
            Node* mid = getMid();

            Node* revStart = rev(mid->next);

            mid->next = nullptr;

            Node* walkerNode1 = head;
            Node* walkerNode2 = revStart;

            int max = INT64_MIN;
            while(walkerNode1 && walkerNode2) {
                int sum = (walkerNode1->data + walkerNode2->data);
                if(sum > max)
                    max = sum;
                walkerNode1 = walkerNode1->next;
                walkerNode2 = walkerNode2->next;
            }

            return max;
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

    cout << list.twinSum() << endl;

    return 0;
}