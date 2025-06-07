#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
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
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head) {
            tail->next = newNode;
            tail = newNode;
        } else {
            head = newNode;
            tail = newNode;
        }
    }

    void printList() {
        if(head == nullptr){
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

    Node* getHead() {
        return head;
    }

    ~LinkedList() {
        Node* curr = head;
        Node* nextNode = nullptr;

        while (curr) {
            nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }

        head = nullptr;
        tail = nullptr;
    }
};

// Function to find the middle of the list
Node* getMid(Node* head) {
    if(head == nullptr)
        return head;

    Node* slow = head;
    Node* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to reverse the linked list starting from the given node
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* nextNode = nullptr;

    while (curr != nullptr) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

// Function to check if the linked list is a palindrome
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return true;

    // Find the middle of the list
    Node* mid = getMid(head);

    // Reverse the second half of the list and store the new head of the reversed half
    Node* secondHalfStart = reverse(mid->next);

    // Disconnect the first half from the second half
    mid->next = nullptr;

    // Checking if the list is a palindrome
    Node* firstHalfStart = head;
    Node* secondHalfIter = secondHalfStart;
    bool isPalin = true;

    while (secondHalfIter != nullptr) {
        if (firstHalfStart->data != secondHalfIter->data) {
            isPalin = false;
            break;
        }
        firstHalfStart = firstHalfStart->next;
        secondHalfIter = secondHalfIter->next;
    }

    // Restore the second half to its original state
    mid->next = reverse(secondHalfStart);

    return isPalin;
}

int main() {
    system("cls");
    LinkedList list;

    int input;
    cin >> input;

    while(input != -1){
        list.createNode(input);
        cin >> input;
    }

    cout << boolalpha;
    cout << isPalindrome(list.getHead()) << "\n";
    list.printList();

    try{
        if(getMid(list.getHead()) == nullptr)
            throw runtime_error("Dereferencing a nullptr.");
    }
    catch(const exception& e){
        cout << e.what() << endl;
    }
    

    return 0;
}
