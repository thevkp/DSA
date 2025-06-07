#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

class LinkedList{
    private:
        Node* head;
        Node* tail;
    public:
        LinkedList(){
            head = nullptr;
            tail = nullptr;
        }


        void createNode(int value){
            Node* temp = new Node();
            temp->data = value;
            temp->next = nullptr;

            if(head == nullptr){
                head = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                tail = temp;
            }
        }

        void pushNode(int value){
            Node* new_node = new Node();
            new_node->data = value;
            new_node->next = nullptr;

            // linking 
            new_node->next = head;
            head = new_node;
        }


        int pop(){
            if(head == nullptr){
                return -1;
            }

            int poppedValue = head->data;

            Node* firstNode = head;
            head = head->next;
            delete firstNode;

            return poppedValue;
        }


        void removeLast(){
            if(head == nullptr){
                cout << "List is empty." << endl;
                return;
            }

            // if list has single node
            if(head->next == nullptr){
                delete head;
                head = nullptr;
                return;
            }

            // finding second-to-last node
            Node* current = head;
            while(current->next->next != nullptr){
                current = current->next;
            }

            delete current->next;
            current->next = nullptr;
        }


        void addToPos(int pos, int value){
            if(!head && !pos) {
                createNode(value);
                return;
            };

            // creating the node;
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = nullptr;

            if(pos == 0){
                newNode->next = head;
                head = newNode;
                return;
            }

            // traversing to the node before the specified position
            Node* walkerNode = head;
            Node* nextNode = nullptr;

            for(int i = 0; i < pos - 1 && walkerNode; i++){
                walkerNode = walkerNode->next;
            }

            // checking position is valid
            if(!walkerNode) return;

            nextNode = walkerNode->next;
            walkerNode->next = newNode;
            newNode->next = nextNode;
        }


        void deleteNodeAtPosition(int pos){
            if(head == nullptr){
                cout << "List is empty." << "\n";
                return;
            }
            // if(head->next == nullptr){
            //     delete head;
            //     head = nullptr;
            // }
            if(pos == 0){
                Node* current = head;
                head = head->next;
                delete current;
                return;
            }

            // travesing to the specified postion
            Node* walkerNode = head;
            for(int i = 0; walkerNode != nullptr && i < pos - 1; i++){
                walkerNode = walkerNode->next;
            }

            // if position is greater than the  number of nodes
            if(walkerNode == nullptr || walkerNode->next == nullptr){
                cout << "Position out of range." << "\n";
                return;
            }

            cout << walkerNode->data << endl;

            Node* nextPositionNode = walkerNode->next->next;
            delete walkerNode->next;
            walkerNode->next = nextPositionNode;
        }


        void printList(){
            Node* current = head;

            if(current == nullptr){
                cout << "List is empty." << endl;
                return;
            }

            while(current != nullptr){
                cout << current->data << " ";
                current = current->next;
            }

            cout << endl;
        }
        
        void deleteList(){
            Node* current = head;
            Node* nextNode;
            while(current != nullptr){
                nextNode = current->next;
                delete current;
                current = nextNode;
            }

            head = nullptr;
        }

        ~LinkedList(){
            Node* current = head;
            Node* nextNode;
            while(current != nullptr){
                nextNode = current->next;
                delete current;
                current = nextNode;
            }
            head = nullptr;
        }
};


int main(){
    system("cls");
    LinkedList list;
    // list.createNode(1);
    // list.createNode(2);
    // list.createNode(3);
    // list.createNode(4);
    // list.createNode(5);

    int input;
    cin >> input;
    
    while(input != -1){
        list.createNode(input);
        cin >> input;
    }

    // cin >> position;
    // list.printList();

    // list.pushNode(6);
    // list.pushNode(7);

    // list.deleteList();
    // cout << list.pop() << "\n";
    // list.removeLast();
    // list.printList();
    // list.deleteNodeAtPosition(position);


    // data for adding to the specified postion
    int position, value;
    cin >> position >> value;
    list.addToPos(position, value);

    list.printList();


    return 0;
}