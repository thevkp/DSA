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
            Node* new_node = new Node();
            new_node->data = value;
            new_node->next = nullptr;

            if(head){
                tail->next = new_node;
                tail = new_node;
            }
            else{
                head = new_node;
                tail = new_node;
            }
        }

        void printList(){
            if(head == nullptr){
                cout << "List is empty." << endl;
                return;
            }

            Node* current = head;
            while(current){
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        void reverse(){
            Node* curr = head;
            Node* prev = nullptr;
            while(curr){
                Node* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
            head = prev;
        }

        int mid(){
            Node* turtle = head;
            Node* hare = head;
            while(hare != nullptr && hare->next != nullptr){
                turtle = turtle->next;
                hare = hare->next->next;
            }

            return turtle->data;
        }
        
        bool detectCycle(){
            if(head || head->next)
                return false;
            Node* turtle = head;
            Node* hare = head;

            while(hare || hare->next){
                turtle = turtle->next;
                hare = hare->next->next;
                if(turtle == hare)
                    return true;
            }
            return false;
        }

        ~LinkedList(){
            Node* current = head;
            Node* nextNode = nullptr;
            while(current){
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
    int nodes, input;
    cin >> nodes;
    for(int i = 0; i < nodes; i++){
        cin >> input;
        list.createNode(input);
    }

    // list.printList();
    cout << list.mid() << "\n";
    list.reverse();
    list.printList();

    return 0;
}
