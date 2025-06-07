#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void createNode(int value) {
        // creating the node
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        // linking to the end
        if (head) {
            tail->next = newNode;
            tail = newNode;
        } else {
            head = newNode;
            tail = newNode;
        }
    }

    Node* getHead() {
        return head;
    }

    void addCycle() {
        if (tail != nullptr) {
            tail->next = head;
        }
    }

    void breakCycle(){
        if(tail != nullptr){
            tail->next = nullptr;
        }
    }

    void printList(){
        Node* walkerNode = head;
        while(walkerNode != nullptr){
            cout << walkerNode->data << " ";
            walkerNode = walkerNode->next;
        }
    }

    ~LinkedList() {
        // Before deleting nodes, break any potential cycle
        if (tail != nullptr) {
            tail->next = nullptr;
        }

        Node* walkerNode = head;
        while (walkerNode) {
            Node* nextNode = walkerNode->next;
            delete walkerNode;
            walkerNode = nextNode;
        }
        head = nullptr;
        tail = nullptr;
    }
};

bool detectCycle(Node* head) {
    if (head == nullptr) {
        return false;
    }
    Node* turtle = head;
    Node* hare = head;

    while (hare != nullptr && hare->next != nullptr) {
        turtle = turtle->next;
        hare = hare->next->next;
        if (turtle == hare) {
            return true;
        }
    }

    return false;
}

int main() {
    system("cls");
    LinkedList list;

    int nodes, input;
    cin >> nodes;
    for (int i = 0; i < nodes; i++) {
        cin >> input;
        list.createNode(input);
    }

    list.addCycle(); // Create a cycle for testing
    cout << boolalpha;
    cout << detectCycle(list.getHead()) << endl;
    list.breakCycle();
    list.printList();

    return 0;
}

// endl of the code
// code ended