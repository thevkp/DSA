#include <iostream>
using namespace std;

class LinkedList{
    private:
        // Node structure for the doubly linked list
        struct Node{
            Node* prev;
            int data;
            Node* next;

            Node(int value) : data(value), prev(nullptr), next(nullptr){}
        };

        Node* head;
        Node* tail;
        int size;
    public:
        // constructor to initialize an empty list
        LinkedList() : head(nullptr), tail(nullptr), size(0) {}

        // destructor to free memory
        ~LinkedList(){
            clear();
        }


        // add element to the front
        void push_front(int value){
            // creating the node
            Node* newNode = new Node(value);

            // linking to the front
            if(head){
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            else{
                head = tail = newNode;
            }
            size++;
        }


        // add element to the end  
        void push_back(int value){
            // creating the Node
            Node* newNode = new Node(value);

            // linking to the end
            if(tail){
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            else{
                head = tail = newNode;
            }
            size++;
        }

        // Removing elements from the front
        void pop_front(){
            if(head == nullptr){
                cout << "List is empty." << endl;
                return;
            }

            Node* temp = head;
            head = head->next;
            if(head != nullptr){
                head->prev = nullptr;
            }
            else{
                tail = nullptr; // list becomes empty
            }
            delete temp;
            size--;
        }

        // Removing elements from the end
        void pop_back(){
            if(tail == nullptr){
                cout << "List is empty." << endl;
                return;
            }

            Node* temp = tail;
            tail = tail->prev;
            if(tail != nullptr){
                tail->next = nullptr;
            }
            else{
                head = nullptr; // if list becomes empty
            }
            delete temp;
            size--;
        }


        // Print list from the front
        void printForward(){
            if(!head){
                cout << "List is empty." << endl;
                return;
            }

            Node* walkerNode = head;
            while(walkerNode){
                cout << walkerNode->data << " ";
                walkerNode = walkerNode->next;
            }
            cout << endl;
        }

        // Print the list from the end
        void printBackward(){
            Node* walkerNode = tail;
            while(walkerNode){
                cout << (*walkerNode).data << " ";
                walkerNode = (*walkerNode).prev;
            }
            cout << endl;
        }

        // get size
        int getSize() const {
            return size;
        }

        void clear(){
            while(head){
                pop_front();
            }
        }
};

int main(){
    LinkedList list;

    int input;
    cin >> input;
    while(input != -1){
        list.push_back(input);
        cin >> input;
    }
    list.printForward();
    list.printBackward();

    return 0;
}