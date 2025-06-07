#include <iostream>
#include <cstdlib>
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
    LinkedList() : head(nullptr), tail(nullptr) {}

    Node* getHead() {
        return head;
    }

    void createNode(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head != nullptr) {
            tail->next = newNode;
            tail = newNode;
        } else {
            head = newNode;
            tail = newNode;
        }
    }

    void printList() {
        Node* walkerNode = head;
        while (walkerNode != nullptr) {
            cout << walkerNode->data << " ";
            walkerNode = walkerNode->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        Node* walkerNode = head;
        Node* nextNode = nullptr;

        while (walkerNode != nullptr) {
            nextNode = walkerNode->next;
            delete walkerNode;
            walkerNode = nextNode;
        }

        head = nullptr;
        tail = nullptr;
    }

    // Method to find the intersection node if it exists
    Node* findIntersection(Node* otherHead) {
        if (!head || !otherHead) return nullptr;

        // Getting lengths and tails
        int len1 = 0, len2 = 0;
        Node* temp1 = head;
        Node* temp2 = otherHead;

        while (temp1) {
            len1++;
            if (!temp1->next) break;
            temp1 = temp1->next;
        }

        while (temp2) {
            len2++;
            if (!temp2->next) break;
            temp2 = temp2->next;
        }

        // If tails are different, no intersection
        if (temp1 != temp2) return nullptr;

        // Aligning starts
        temp1 = head;
        temp2 = otherHead;
        if (len1 > len2) {
            for (int i = 0; i < len1 - len2; i++) {
                temp1 = temp1->next;
            }
        } else {
            for (int i = 0; i < len2 - len1; i++) {
                temp2 = temp2->next;
            }
        }

        // Finding intersection
        while (temp1 != temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return temp1; // This is the intersection node
    }

    // Adjust the destructor to prevent double-free
    void safeDestructor(Node* intersectionNode) {
        Node* walkerNode = head;
        Node* nextNode = nullptr;

        while (walkerNode != nullptr) {
            if (walkerNode == intersectionNode) {
                break; // Stop at the intersection point to prevent double-free
            }
            nextNode = walkerNode->next;
            delete walkerNode;
            walkerNode = nextNode;
        }

        head = nullptr;
        tail = nullptr;
    }

    void customDestructor(LinkedList& otherList) {
        Node* intersectionNode = findIntersection(otherList.getHead());
        if (intersectionNode) {
            safeDestructor(intersectionNode);
        } else {
            ~LinkedList(); // No intersection, so delete the entire list
        }
    }
};

// Function to intersect two lists
void intersectList(Node* head1, Node* head2, int interPos1, int interPos2) {
    if (head1 == nullptr || head2 == nullptr) return;

    Node* walkerNode1 = head1;
    for (int i = 0; walkerNode1 != nullptr && i < interPos1; i++) {
        walkerNode1 = walkerNode1->next;
    }

    Node* walkerNode2 = head2;
    for (int i = 0; walkerNode2 != nullptr && i < interPos2; i++) {
        walkerNode2 = walkerNode2->next;
    }

    if (walkerNode1 != nullptr && walkerNode2 != nullptr) {
        walkerNode1->next = walkerNode2;
    }
}

int main() {
    LinkedList list1;
    LinkedList list2;

    int input1, input2;
    cin >> input1;
    while (input1 != -1) {
        list1.createNode(input1);
        cin >> input1;
    }

    cin >> input2;
    while (input2 != -1) {
        list2.createNode(input2);
        cin >> input2;
    }

    int interPoint1, interPoint2;
    cin >> interPoint1 >> interPoint2;

    intersectList(list1.getHead(), list2.getHead(), interPoint1, interPoint2);

    list1.printList();
    list2.printList();

    list1.customDestructor(list2);  // This will delete list1 safely
    list2.customDestructor(list1);  // This will delete list2 safely

    return 0;
}
