#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList{
    private:
        Node* head;
        Node* tail;
    public:
        LinkedList() : head(nullptr), tail(nullptr) {};

    void createNode(int value){
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

    Node* getHead(){
        return head;
    }

    ~LinkedList(){
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

bool isPresent(Node* head, int k){
    if(!head)
        return false;
    
    if(head->data == k)
        return true;
    else    
        isPresent(head->next, k);
}

int findIndex(Node* head, int k, int index = 0){
    if(!head)
        return -1;
    
    if(head->data == k && head != nullptr)
        return index;
    
    return findIndex(head->next, k, index + 1);
}

int main(){
    system("cls");
    LinkedList list;

    int input;
    cin >> input;
    while(input != -1){
        list.createNode(input);
        cin >> input;
    }

    int key;
    cin >> key;

    cout << boolalpha;
    cout << isPresent(list.getHead(), key) << endl;
    cout << findIndex(list.getHead(), key) << endl;

    // list.printList();


    return 0;
}