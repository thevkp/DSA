#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int x) : val(x), next(nullptr) {};
};

class LinkedList {
    private:
        Node* head;
        // Node* tail;
    public:
        LinkedList() : head(nullptr) {};

        ~LinkedList(){
            deleteList();
        }

        Node* getHead(){
            return head;
        }

        void insert(int value){
            Node* newNode = new Node(value);

            if(head == nullptr) {
                head = newNode;
                return;
            }

            Node* walkerNode =  head;
            while(walkerNode->next){
                walkerNode = walkerNode->next;
            }

            walkerNode->next = newNode;
        }

        void printList(){
            if(head == nullptr) {
                cout << "List is empty." << endl;
                return;
            }

            Node* walkerNode = head;
            while(walkerNode){
                cout << walkerNode->val << "->";
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

            head = nullptr;
        }
};

Node* getMid(Node* node){
    Node* slow = node;
    Node* fast = node->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// uses extra space to store the new merged list
Node*  mergeLists(Node* l1, Node* l2){
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;

    Node* dummy = new Node(-1);
    Node* curr = dummy;
    while(l1 && l2){
        if(l1->val <= l2->val){
            curr->next = l1;
            l1 = l1->next;
        }
        else {
            curr->next = l2;
            l2 = l2->next;
        }

        curr = curr->next;
    }

    if(l1) curr->next = l1;
    if(l2) curr->next = l2;


    Node* mergedHead = dummy->next;
    delete dummy;
    return mergedHead;

}


Node* sortList(Node* head){
    if(head == nullptr || head->next == nullptr)
        return head;

    // split the list into two halves
    Node* mid = getMid(head);
    Node* rightHalf = mid->next;
    mid->next = nullptr;

    // recursively sort both halves
    Node* leftSorted = sortList(head);
    Node* rightSorted = sortList(rightHalf);

    return mergeLists(leftSorted, rightSorted);
}

void printList(Node* head){
    if(head == nullptr){
        cout << "List is empty." << endl;
        return;
    }

    Node* walkerNode = head;
    while(walkerNode){
        cout << walkerNode->val << "->";
        walkerNode = walkerNode->next;
    }
    cout << "-1" << endl;
}

int main(){
    system("cls");
    
    LinkedList list;

    int input;
    cin >> input;
    while(input != -1){
        list.insert(input);
        cin >> input;
    }

    list.printList();
    Node* head = sortList(list.getHead());
    printList(head);

    return 0;
}