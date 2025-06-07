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
            while(walkerNode && k > 1){
                walkerNode = walkerNode->next;
                k--;
            }

            return walkerNode;
        }

        Node* reverseKGroup(int k){
            Node dummy(0);
            dummy.next = head;
            Node* prevGroupEnd = &dummy;
            Node* curr = head;
            
            while(true){
                Node* kth = getKthNode(curr, k);
                if(!kth) return dummy.next;

                Node* prev = nullptr;
                Node* nextNode = nullptr;
                Node* currGroupTail = curr;
                for(int i = 0 ; i < k; i++){
                    nextNode = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = nextNode;
                }
                
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
    SLL list;

    int n;
    cin >> n;
    
    int input;
    for(int i = 0; i < n; i++){
        cin >> input;
        list.append(input);
    }
    
    int groupSize;
    cin >> groupSize;

    Node* newHead = list.reverseKGroup(groupSize);
    list.setHead(newHead);
    list.printList();

    return 0;
}