#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;


    Node(int value) : data(value), next(nullptr) {}
};


class Queue{
    private:
        Node* head; 
        Node* tail;
        int size;
    public:
        Queue(){
            head = tail = nullptr;
            size = 0;
        }

        ~Queue(){
            deleteList();
        }

        void push(int value){
            Node* newNode = new Node(value);

            if(head){
                tail->next = newNode;
                tail = newNode;
                size += 1;
            }
            else{
                head = tail = newNode;
                size += 1;
            }
        }

        int pop(){
            if(!head)
                throw runtime_error("queueUnderflow");
            
            if(!head->next){
                int val = head->data;
                Node* temp = head;
                head = head->next;
                delete temp;
                size -= 1;
                return val;
            }

            Node* walkerNode = head;
            while(walkerNode->next && walkerNode->next->next){
                walkerNode = walkerNode->next;
            }
            
            int val = walkerNode->next->data;
            tail = walkerNode;
            delete walkerNode->next;
            size -= 1;
            tail->next = nullptr;
            return val;
        }

        bool empty(){
            return size == 0 || head == nullptr;
        }

        void printList(){
            if(!head)
                return;

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
};



int main(){
    // system("cls");

    Queue q;

    int input;
    cin >> input;

    while(input != -1){
        q.push(input);
        cin >> input;
    }

    q.printList();
    cout << boolalpha;
    cout << q.empty() << endl;
    try{
        cout << q.pop() << endl;
        q.printList();
        cout << q.pop() << endl;
        q.printList();
        cout << q.pop() << endl;
        q.printList();
        cout << q.pop() << endl;
        q.printList();
        cout << q.pop() << endl;
        q.printList();
        cout << q.pop() << endl;
        q.printList();
        cout << q.pop() << endl;
        q.printList();
    }
    catch(const exception& e){
        cout << e.what() << endl;
    }

    cout << q.empty() << endl;

    // q.deleteList();
    // q.printList();


    return 0;
}