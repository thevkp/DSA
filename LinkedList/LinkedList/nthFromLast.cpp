#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
    private:
        Node* head;
        Node* tail;

    public:
        LinkedList() : head(nullptr), tail(nullptr) {}

        void createNode(int value) {
            Node* newNode = new Node(value);

            if (head) {
                tail->next = newNode;
                tail = newNode;
            } else {
                head = newNode;
                tail = newNode;
            }
        }

        void printList() {
            if (!head) {
                std::cout << "List is empty." << std::endl;
                return;
            }
            Node* walkerNode = head;
            while (walkerNode != nullptr) {
                std::cout << walkerNode->data << " ";
                walkerNode = walkerNode->next;
            }
            std::cout << std::endl;  // Add a newline for better output formatting
        }

        // Remove head
        void pop_front() {
            if (!head) {
                return;
            }

            Node* temp = head;
            if (head->next == nullptr) {  // List has a single node
                head = tail = nullptr;
            } else {
                head = head->next;
            }
            delete temp;
        }

        // Free the memory
        void clear() {
            while (head) {
                pop_front();
            }
        }

        ~LinkedList() {
            clear();  // Ensure all nodes are deleted
        }

        int nthFromLast(int n){
            Node* turtle = head;
            Node* hare = head;

            for(int i = 0; i < n && hare; i++){
                hare = hare->next;
            }

            while(hare){
                turtle = turtle->next;
                hare = hare->next;
            }

            return turtle->data;
        }
};

int main() {
    std::system("cls");  // Optional, can be removed for non-Windows platforms
    LinkedList list;

    int input;
    std::cin >> input;
    while (input != -1) {  // Stop input when -1 is entered
        list.createNode(input);
        std::cin >> input;
    }

    list.printList();

    int k;
    cin >> k;

    cout << list.nthFromLast(k) << endl;

    return 0;
}
