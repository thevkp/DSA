#include <iostream>
using namespace std;

template <typename T>
class LinkedListNode {
public:
    T data;
    LinkedListNode<T> *next;

    LinkedListNode(T value) {
        this->data = value;
        this->next = nullptr;
    }
};

template <typename T>
class LinkedList {
public:
    LinkedListNode<T> *head;
    LinkedListNode<T> *tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void createNode(T value) {
        LinkedListNode<T>* newNode = new LinkedListNode<T>(value);
        if (head) {
            tail->next = newNode;
            tail = newNode;
        } else {
            head = newNode;
            tail = newNode;
        }
    }

    bool isPalindrome() {
        if (head == nullptr || head->next == nullptr)
            return true;

        // Find the middle of the linked list
        LinkedListNode<T>* turtle = head;
        LinkedListNode<T>* hare = head;

        while (hare && hare->next) {
            turtle = turtle->next;
            hare = hare->next->next;
        }

        // Reverse the second half
        LinkedListNode<T>* prev = nullptr;

        while (turtle) {
            LinkedListNode<T>* nextNode = turtle->next;
            turtle->next = prev;
            prev = turtle;
            turtle = nextNode;
        }

        // Compare the two halves
        LinkedListNode<T>* start = head;
        LinkedListNode<T>* end = prev;

        while (end) {
            if (start->data != end->data)
                return false;
            start = start->next;
            end = end->next;
        }

        return true;
    }
};

int main() {
    LinkedList<int> list;

    int nodes, input;
    cin >> nodes;
    for (int i = 0; i < nodes; i++) {
        cin >> input;
        list.createNode(input);
    }

    if (list.isPalindrome()) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
