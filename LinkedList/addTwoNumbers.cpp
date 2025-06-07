// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.


#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {};
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
    public:
        LinkedList() : head(nullptr) {};

        ~LinkedList() {
            deleteList();
        }

        Node* getHead(){
            return  head;
        }

        void insert(int value) {
            Node* newNode = new Node(value);
            if(head){
                tail->next = newNode;
                tail = newNode;
            }
            else {
                head = tail = newNode;
            }
        }

        void printList(){
            if(head == nullptr) {
                cout << "List is empty." << endl;
                return;
            }

            Node* walkerNode = head;
            while(walkerNode){
                cout << walkerNode->data << "->";
                walkerNode = walkerNode->next;
            }
            cout << "-1" << endl;
        }

        void deleteList(){
            if(head == nullptr) return;

            Node* walkerNode = head;
            Node* nextNode = nullptr;
            while(walkerNode){
                nextNode = walkerNode->next;
                delete walkerNode;
                walkerNode = nextNode;
            }

            head = tail = nullptr;
        }
};

// Function to add two numbers represented by linked lists
LinkedList addTwoNumbers(Node* l1, Node* l2) {
    LinkedList result;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->data;
            l2 = l2->next;
        }

        result.insert(sum % 10);
        carry = sum / 10;
    }

    return result;
}



int main(){
    system("cls");

    LinkedList list1, list2;

    int input1;
    cin >> input1;

    while(input1 != -1){
        list1.insert(input1);
        cin >> input1;
    }

    list1.printList();

    int input2;
    cin >> input2;

    while(input2  != -1){
        list2.insert(input2);
        cin >> input2;
    }

    list2.printList();

    LinkedList result = addTwoNumbers(list1.getHead(), list2.getHead());

    result.printList();

    return 0;
}