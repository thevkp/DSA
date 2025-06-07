#include <iostream>
using namespace std;

class Queue {
private:
    struct Node {
        int data;
        Node* next;

        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

    void addNode(int value) {
        Node* newNode = new Node(value);

        if (head) {
            tail->next = newNode;
            tail = newNode;
            size += 1;
        } else {
            head = tail = newNode;
            size += 1;
        }
    }

    void removeNode() {
        if (!head)
            throw runtime_error("Queue Underflow");

        if (!head->next) {
            Node* temp = head;
            head = tail = nullptr;
            delete temp;
            size -= 1;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        size -= 1;
    }

    int getFront() {
        if (!head)
            throw runtime_error("Queue Underflow");

        return head->data;
    }

    void clearQueue() {
        Node* current = head;
        Node* nextNode = nullptr;

        while (current) {
            nextNode = current->next;
            delete current;
            size -= 1;
            current = nextNode;
        }

        head = tail = nullptr;
    }

public:
    Queue() : head(nullptr), tail(nullptr), size(0) {}

    ~Queue() {
        clearQueue();
    }

    void enqueue(int value) {
        addNode(value);
    }

    void dequeue() {
        removeNode();
    }

    int front() {
        return getFront();
    }

    bool isEmpty() {
        return size == 0 || head == nullptr;
    }
};

int main() {
    Queue q;

    int N;
    cin >> N;

    while (N--) {
        try {
            string operation;
            cin >> operation;

            if (operation == "enqueue") {
                int X;
                cin >> X;
                if (X < -1000000 || X > 1000000) {
                    cout << "Value out of range: " << X << endl;
                    continue;
                }
                q.enqueue(X);
            } else if (operation == "dequeue") {
                q.dequeue();
            } else if (operation == "front") {
                cout << q.front() << endl;
            } else if (operation == "isEmpty") {
                cout << boolalpha;
                cout << q.isEmpty() << endl;
            } else {
                cout << "Invalid Operation" << endl;
            }
        } catch (const exception& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}
