#include <iostream>
using namespace std;

class SLL {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    SLL() {
        head = tail = nullptr;
    }

    ~SLL() {
        deleteList();
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head) {
            tail->next = newNode;
            tail = newNode;
        } else {
            head = tail = newNode;
        }
    }

    void deleteList() {
        Node* curr = head;
        Node* nextNode = nullptr;
        while (curr) {
            nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
        head = tail = nullptr;
    }

    int middle() {
        if (!head) {
            return -1;
        }
        Node* turtle = head;
        Node* hare = head;
        while (hare != nullptr && hare->next != nullptr) {
            turtle = turtle->next;
            hare = hare->next->next;
        }
        return turtle->data;
    }

    int NthFromLast(int n) {
        if(n <= 0){
            return -1;
        }

        Node* turtle = head;
        Node* hare = head;

        
        for (int i = 0; i < n; i++) { 
            hare = hare->next;
        }

        if (!hare) return -1;

        while (hare) {
            turtle = turtle->next;
            hare = hare->next;
        }

        return turtle->data;
    }
};

int main() {
    system("cls");

    SLL list;
    int N;
    cin >> N;

    int input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        list.insert(input);
    }

    int pos;
    cin >> pos;

    cout << list.NthFromLast(pos) << endl;

    return 0;
}
