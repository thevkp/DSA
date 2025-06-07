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

        Node* getKthNode(int k){
            if(k <= 0){
                throw runtime_error("Invalid position");
            }

            if(!head){
                throw runtime_error("List empty");
            }

            Node* walkerNode = head;
            while(walkerNode && --k){
                walkerNode = walkerNode->next;
            }

            if(!walkerNode){
                throw runtime_error("Invalid position");
            }

            return walkerNode;
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
        int k, c;
        cin >> k >> c;

        try{
            Node* node = list.getKthNode(k);
            cout << node->data << endl;
            cout << boolalpha << list.countKAheadNodes(node, c) << endl;
        }
        catch(const exception& e){
            cout << e.what() << endl;
        }
    }


    return 0;
}