#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList{
    private:
        // function to create the node
        void insertNode(int value){
            Node* newNode = new Node(value);

            if(head){
                tail->next = newNode;
                tail = newNode;
            }
            else
                head = newNode;
                tail = newNode;
        }
        
        // function to print list
        void print(){
            if(head == nullptr){
                cout << "List is empty." << endl;
                return;
            }

            Node* walkerNode = head;
            while(walkerNode){
                cout << walkerNode->data << "->";
                walkerNode = walkerNode->next;
            }
            cout << -1 << endl;
        }

        // reverse the list
        Node* reverseList(Node* head){
            if (head == nullptr || head->next == nullptr)
                return head;
            
            Node* curr = head;
            Node* prev = nullptr;
            Node* nextNode = nullptr;
            tail = head;
            while(curr != nullptr){
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            return prev;
        }

        // find the mid of the list
        Node* getMid(Node* head){
            if(head == nullptr || head->next == nullptr)
                return head;
            
            Node* turtle = head;
            Node* hare = head;

            while(hare && hare->next){
                turtle = turtle->next;
                hare = hare->next->next;
            }

            return turtle;
        }

        // deallocate the memory
        void deleteList(){
            if(head == nullptr) 
                return;
            
            Node* walkerNode = head;
            Node* nextNode = nullptr;

            while(walkerNode){
                nextNode = walkerNode->next;
                delete walkerNode;
                walkerNode = nextNode;
            }
            head = tail = nullptr;
        }
    public:
        Node* head;
        Node* tail;

        LinkedList() : head(nullptr), tail(nullptr) {}

        ~LinkedList(){
            deleteList();
        }

        // take inputs and insert them to the end of list
        void insert(){
            int input;
            cin >> input;

            while(input != -1){
                insertNode(input);
                cin >> input;
            }
        }

        void printList(){
            print();
        }

        void reverse(){
            head = reverseList(head);
        }

        Node* getTail(){
            return tail;
        }

        bool isPalindrome(){
            if(head == nullptr || head->next == nullptr)
                return true;
            Node* mid = getMid(head);
            Node* secondHalfStart = reverseList(mid->next);
            mid->next = nullptr;

            Node* firstHalfStart = head;
            Node* secondHalfIterator = secondHalfStart;
            bool isPalin = true;

            while(secondHalfIterator != nullptr){
                if(firstHalfStart->data != secondHalfIterator->data){
                    isPalin = false;
                    break;
                }

                firstHalfStart = firstHalfStart->next;
                secondHalfIterator = secondHalfIterator->next;
            }

            mid->next = reverseList(secondHalfStart);
            return isPalin;
        }
};


int main(){
    system("cls");
    LinkedList list;

    list.insert();
    list.printList();
    list.reverse();
    list.printList();

    Node* walkerNode = list.getTail();
    while(walkerNode){
        cout << walkerNode->data << " ";
        walkerNode = walkerNode->next;
    }
    cout << endl;

    cout << boolalpha;
    cout << list.isPalindrome() << endl;

    return 0;
}