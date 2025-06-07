#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
};

class LinkedList {
    private:
        Node* head;
    public:
        LinkedList() : head(nullptr) {}

        void addToEnd(int value) {
            // Creating the node
            Node* newNode = new Node();
            newNode->prev = nullptr;
            newNode->data = value;
            newNode->next = nullptr;

            if (head == nullptr) {
                head = newNode;
                return;
            }

            // Traversing to the last
            Node* walkerNode = head;
            while (walkerNode->next != nullptr)
                walkerNode = walkerNode->next;

            // Linking
            walkerNode->next = newNode;
            newNode->prev = walkerNode;
        }

        void addAtBeg(int value) {
            // Creating the Node
            Node* newNode = new Node();
            newNode->prev = nullptr;
            newNode->data = value;
            newNode->next = head;

            if (head != nullptr) {
                head->prev = newNode;
            }

            head = newNode;
        }

        Node* getHead() {
            return head;
        }

        void printList() {
            if (head == nullptr) {
                cout << "List is empty." << endl;
                return;
            }

            Node* walkerNode = head;
            while (walkerNode) {
                cout << walkerNode->data << " ";
                walkerNode = walkerNode->next;
            }
            cout << endl;
        }

        void deleteAlternateNodes() {
            if (!head || !head->next) {
                return;
            }

            Node* prev = head;
            Node* curr = head->next;

            while (curr) {
                prev->next = curr->next;
                Node* temp = curr;
                curr = curr->next;
                delete temp;

                if(curr){
                    prev = curr;
                    curr = curr->next;
                }
            }
        }

        ~LinkedList() {
            Node* walkerNode = head;
            while (walkerNode) {
                Node* nextNode = walkerNode->next;
                delete walkerNode;
                walkerNode = nextNode;
            }
            head = nullptr;
        }
};

void printReverse(Node* head) {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }

    Node* walkerNode = head;
    while (walkerNode->next != nullptr) {
        walkerNode = walkerNode->next;
    }

    while (walkerNode) {
        cout << walkerNode->data << " ";
        walkerNode = walkerNode->prev;
    }
    cout << endl;
}

int nthFromLast(Node* head, int pos) {
    if (!head) {
        cout << "List is empty." << endl;
        return -1;
    }

    Node* forward = head;
    Node* backward = head;

    for (int i = 0; i < pos; ++i) {
        if (!forward) {
            cout << "Position out of bounds." << endl;
            return -1;
        }
        forward = forward->next;
    }

    while (forward) {
        forward = forward->next;
        backward = backward->next;
    }

    return backward->data;
}

int main() {
    system("cls");
    LinkedList list;

    int input;
    cin >> input;
    while (input != -1) {
        list.addToEnd(input);
        cin >> input;
    }

    printReverse(list.getHead());
    list.deleteAlternateNodes();
    list.printList();

    int pos;
    cin >> pos;
    cout << nthFromLast(list.getHead(), pos) << endl;

    return 0;
}
