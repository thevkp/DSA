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
        int listLength;
    public:
        SLL() : head(nullptr), listLength(0){}
        ~SLL() { deleteList(); }

        void append(int value){
            Node* newNode = new Node(value);

            if(head){
                tail->next = newNode;
                tail = newNode;
                listLength++;
            }
            else{
                head = tail = newNode;
                listLength++;
            }
        }

        void printList(){
            if(!head){
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

        const int length(){
            return listLength;
        }

        void reverseSublist(int p, int q){
            if (!head || p >= q || p <= 0 || q <= 0)
                return;

            Node dummy(0);
            dummy.next = head;

            Node* sublistStartPrev = &dummy;

            for(int i = 1; i < p && sublistStartPrev; i++){
                sublistStartPrev = sublistStartPrev->next;
            }

            if(!sublistStartPrev || !sublistStartPrev->next)
                return;


            Node* curr = sublistStartPrev->next;
            Node* prev = nullptr;
            Node* nextNode = nullptr;

            for(int i = 0; i <= q - p && curr; i++){
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            Node* sublistTail = sublistStartPrev->next;
            sublistStartPrev->next = prev;
            sublistTail->next = nextNode;

            head = dummy.next;

            if(!nextNode){
                tail = sublistTail;
            }
        }

        void reverseSkip(int k){
            if(k <= 0 || !head || !head->next)
                return;

            Node dummy(0);
            dummy.next = head;

            Node* groupStartPrev = &dummy;
            
        }

        
};


int main(){
    system("cls");

    SLL list;

    int t;
    cin >> t;

    int input;
    cin >> input;
    while(input != -1){
        list.append(input);
        cin >> input;
    }

    while(t--){
        int s, e;
        cin >> s >> e;


    }


    return 0;
}

// 14
// 1 2 3 4 5 -1
// 1 3
// 0 3
// 0 0
// 1 1
// 2 3
// 4 5
// 2 5
// 1 5
// 1 2
// 1 4
// 2 4
// 3 4
// 5 5
// 5 6