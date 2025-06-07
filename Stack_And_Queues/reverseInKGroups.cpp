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
            // if(k <= 0){
            //     throw runtime_error("Invalid position");
            // }

            // if(!head){
            //     throw runtime_error("List empty");
            // }

            Node* walkerNode = node;
            while(walkerNode && k > 0){
                walkerNode = walkerNode->next;
                k--;
            }

            return walkerNode;
        }


        void reverseInKGroups(int k){
            if(k <= 0){
                return;
            }
            if(!head || !head->next)
                return;

            Node dummy(0);
            dummy.next = head;

            Node* groupStartPrev = &dummy;
            Node* newHead = groupStartPrev;
            while(true){
                Node* kth = getKthNode(groupStartPrev, k);
                if(!kth) break;

                Node* curr = dummy.next;
            }
        }
};



int main(){
    system("cls");

    

    return 0;
}