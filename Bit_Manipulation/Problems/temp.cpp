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
        SLL(){
            head = nullptr;
            tail = nullptr;
        }

        ~SLL(){
            deleteList();
        }

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

        int getTail(){
            return tail->data;
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
};




int main(){
    system("cls");

    SLL list;

    int n;
    cin >> n;

    int input;
    cin >> input;
    list.append(input);
    n--;
    for(int i = 0; i < n; i++){
        cin >> input;
        if(input == list.getTail()){
            continue;
        }
        list.append(input);
    }

    list.printList();
    // cout << list.getTail() << endl;
    
    
    return 0;
}