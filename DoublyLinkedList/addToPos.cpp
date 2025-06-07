#include <iostream>
using namespace std;

class LinkedList{
    private:
        // Node structure to hold the components of a node
        struct Node{
            Node* prev;
            int data;
            Node* next;

            Node(int value) : data(value), prev(nullptr), next(nullptr) {}
        };

    Node* head;
    Node* tail;
    int size;
    public:
        // constructor to initialize the members
        LinkedList() : head(nullptr), tail(nullptr), size(0) {}
        
        ~LinkedList(){
            clear();
        }

        // Add element to the front
        void push_front(int value){
            // creating the node
            Node* newNode = new Node(value);
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
        
        // Add element to the end 
        void push_back(int value){
            // creating the node
            Node* newNode = new Node(value);
            if(tail){
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
            else{
                head = tail = newNode;
            }
            size++; 
        }

        // Add element between the nodes
        void push_pos(int value, int pos){
            //checking if position is valid
            if(pos == 0 || pos > size){
                cout << "Invalid position." << endl;
                return;
            }
            // creating the node;
            Node* newNode = new Node(value);

            // if Position = 0, insert at the front
            if(pos == 0){
                push_front(value);
                return;
            }

            // if position = size, insert at the end
            if(pos == size){
                push_back(value);
                return;
            }
            // traversing to the node before specified position
            Node* walkerNode = head;
            for(int i = 0; i < pos - 1 && walkerNode; i++){
                walkerNode = walkerNode->next;
            }

            // linking the node
            newNode->next = walkerNode->next;
            newNode->prev = walkerNode;
            walkerNode->next->prev = newNode;
            walkerNode->next = newNode;

            // increment the size;
            size++;
            
        }

        // Remove from the front
        void pop_front(){
            if(!head){
                cout << "List is empty." << endl;
                return;
            }

            Node* temp = head;
            head = head->next;
            if(head != nullptr){
                head->prev = nullptr;
            }
            else{
                tail =  nullptr; // if list become empty
            }
            delete temp;
            size--;

        }

        // Remove from the end
        void pop_back(){
            if(tail == nullptr){
                cout << "List is empty." << endl;
                return;
            }

            Node* temp = tail;
            tail = tail->prev;
            if(tail){
                tail->next = nullptr;
            }        
            else{
                head = nullptr; // if list becomes empty
            }
            delete temp;
            size--;
        }

        // Print the list from the start
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

        // Print the list from the end;
        void printBackward(){
            if(!tail){
                cout << "List is empty." << endl;
                return;
            }

            Node* walkerNode = tail;
            while(walkerNode){
                cout << walkerNode->data << " ";
                walkerNode = walkerNode->prev;
            }
            cout << endl;
        }

        // Get size
        int getSize(){
            return size;
        }

        // free the memory
        void clear(){
            while(head){
                pop_front();
                // pop_back();
            }
        };

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

    int pos, value;
    cin >> pos >> value;
    list.push_pos(value, pos);
    list.printForward();
    list.printBackward();

    return 0;
}