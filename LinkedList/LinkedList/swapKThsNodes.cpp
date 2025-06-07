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

        void printList(){
            Node* walkerNode = head;
            while(walkerNode){
                cout << walkerNode->data << " ";
                walkerNode = walkerNode->next;
            }
            cout << endl;
        }

        Node* kthFromStart(int k){
            Node* walkerNode = head;
            for(int i = 1; i < k && walkerNode; i++){
                walkerNode = walkerNode->next;
            }

            if(!walkerNode) return head;

            return walkerNode;
        }


        Node* kthFromLast(int k) {
            Node* turtle = head;
            Node* hare = head;


            for (int i = 0; i < k && hare; i++) { 
                hare = hare->next;
            }

            while (hare) {
                turtle = turtle->next;
                hare = hare->next;
            }

            return turtle;
        }
        
        void swapNodes(int k){
            if(k <= 0) return;

            cout << kthFromStart(k)->data << " " << kthFromLast(k)->data << endl;

            swap(kthFromLast(k)->data, kthFromStart(k)->data);
        }

        void swapKthValues(int k) {
            if (k <= 0 || !head) return;

            Node* start = nullptr;
            Node* end = nullptr;
            Node* hare = head;
            Node* turtle = head;

            for (int i = 1; i < k && hare; i++) {
                hare = hare->next;
            }

            if (!hare) return;  // k > length of list

            start = hare;  // kth from start

            while (hare->next) {
                hare = hare->next;
                turtle = turtle->next;
            }

            end = turtle;  // kth from end

            if (start && end) {
                swap(start->data, end->data);
        }
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
    int k;
    cin >> k;

    // list.swapNodes(k);
    list.printList();
    list.swapKthValues(k);
    list.printList();







    return 0;
}