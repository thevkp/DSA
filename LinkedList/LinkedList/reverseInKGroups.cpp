#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {};
};


class SLL{
    private:
        Node* head;
        Node* tail;
    public:
        SLL() : head(nullptr), tail(nullptr) {}
        ~SLL(){ deleteList(); }

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


        bool countKAheadNodes(Node* node, int k) {
            if (k <= 0) {
                throw runtime_error("Invalid Count");
            }

            Node* walkerNode = node;
            for (int i = 1; i < k && walkerNode; i++) {
                walkerNode = walkerNode->next;
            }

            return walkerNode != nullptr;
        }



        Node* getKthNode(Node* node, int k){
            Node* walkerNode = node;
            while(walkerNode && k > 0){
                walkerNode = walkerNode->next;
            }

            return walkerNode;
        }

        Node* reverseKGroup(int k) {
            if (!head || k == 1) return head;
            // Dummy node to simplify head operations
            Node dummy(0);
            dummy.next = head;
            Node* prevGroupEnd = &dummy;
            Node* curr = head;
            while (true) {
                // Check if we have at least k nodes to reverse
                Node* check = curr;
                for (int i = 0; i < k; ++i) {
                    if (!check) return dummy.next; // not enough nodes left
                    check = check->next;
                }
                // Reverse k nodes
                Node* prev = nullptr;
                Node* currGroupTail = curr; // will become the end after reversal
                Node* nextNode = nullptr;
                for (int i = 0; i < k; ++i) {
                    nextNode = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = nextNode;
                }
                // Connect previous group to reversed
                prevGroupEnd->next = prev;
                currGroupTail->next = curr;
                prevGroupEnd = currGroupTail;

                if(!curr){
                    tail = currGroupTail;
                }
            }
            return dummy.next;
        }

        void setHead(Node* node){
            head = node;
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

    int t;
    cin >> t;

    while(t--){
        int k;
        cin >> k;

        Node* newHead = list.reverseKGroup(k);
        list.setHead(newHead);
        list.printList();
    }


    return 0;
}