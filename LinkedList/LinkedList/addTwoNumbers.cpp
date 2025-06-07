#include <iostream>
using namespace std;

struct Node{    
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};


class SLL{
    private:
        Node* head;
    public:
        SLL(){
            head = nullptr;
        }

        ~SLL(){
            deleteList();
        }

        Node* getHead(){
            return head;
        }

        void addToList(int value){
            Node* newNode = new Node(value);

            newNode->next = head;
            head = newNode;
        }

        void printList(){
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

        void deleteList(){
            Node* curr = head;
            Node* nextNode = nullptr;

            while(curr){
                nextNode = curr->next;
                delete curr;
                curr = nextNode;
            }

            head = nullptr;
        }
};

Node* reverseList(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* nextNode = nullptr;

    while(curr){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}


Node* addTwoNumbers(Node* head1, Node* head2){
    Node* dummy = new Node(-1);
    Node* curr = dummy;

    int carry = 0;
    while(head1 || head2 || carry){
        int sum = carry;

        if(head1){
            sum += head1->data;
            head1 = head1->next;
        }
        if(head2){
            sum += head2->data;
            head2 = head2->next;
        }

        curr->next = new Node(sum % 10);
        curr = curr->next;
        carry = sum / 10;
    }

    Node* head = dummy->next;
    delete dummy;
    head = reverseList(head);
    return head;
}

void printList(Node* head){
    if(!head){
        cout << "List is empty." << endl;
        return;
    }

    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}


int main(){
    system("cls");

    SLL list1, list2;

    int input;
    cin >> input;

    while(input != -1){
        list1.addToList(input);
        cin >> input;
    }


    cin >> input;
    while(input != -1){
        list2.addToList(input);
        cin >> input;
    }

    list1.printList();
    list2.printList();
    // list1.deleteList();
    // list1.printList();

    Node* head = addTwoNumbers(list1.getHead(), list2.getHead());
    printList(head);


    return 0;
}