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
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    Node* getHead() {
        return head;
    }

    // Link node to the last
    void createNode(int value) {
        // Creating the node
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        // If list is not empty
        if (head != nullptr) {
            tail->next = newNode;
            tail = newNode;
        } else {
            head = newNode;
            tail = newNode;
        }
    }

    void printList() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* walkerNode = head;
        while (walkerNode != nullptr) {
            cout << walkerNode->data << " ";
            walkerNode = walkerNode->next;
        }

        cout << endl;
    }

    // Deallocating the memory
    // ~LinkedList() {

    //     Node* walkerNode = head;
    //     Node* nextNode = nullptr;
    //     while (walkerNode != nullptr) {
    //         nextNode = walkerNode->next;
    //         delete walkerNode;
    //         walkerNode = nextNode;
    //     }
    //     head = nullptr;
    //     tail = nullptr;
    // }
};

void intersectList(Node* head1, Node* head2, int interPos1, int interPos2) {
    if (head1 == nullptr || head2 == nullptr || interPos1 < 0 || interPos2 < 0) {
        cout << "One of the lists is empty. Cannot create intersection." << endl;
        return;
    }

    // Traverse to the specified position in list1
    Node* walkerNode1 = head1;
    for (int i = 0; walkerNode1 != nullptr && i < interPos1; i++) {
        walkerNode1 = walkerNode1->next;
    }

    // Traverse to the specified position in list2
    Node* walkerNode2 = head2;
    for (int i = 0; walkerNode2 != nullptr && i < interPos2; i++) {
        walkerNode2 = walkerNode2->next;
    }

    // Checking if the positions are valid in both the lists
    if (walkerNode1 == nullptr || walkerNode2 == nullptr) {
        cout << "Invalid intersection positions." << endl;
        return;
    }

    // Intersecting
    walkerNode1->next = walkerNode2;
}


// detecting if lists intersect
bool hasIntersectionBrute(Node* head1, Node* head2){
    if(head1 == nullptr || head2 == nullptr){
        return false;
    }

    Node* walkerNode1 = head1;
    Node* walkerNode2 = nullptr;
    while(walkerNode1 != nullptr){
        walkerNode2 = head2;
        while(walkerNode2 !=  nullptr){
            if(walkerNode1 == walkerNode2){
                return true;
            }
            walkerNode2 = walkerNode2->next;
        }

        walkerNode1 = walkerNode1->next;
    }

    return false;
}

// Detecting if lists intersect and returning the intersecting node
Node* hasIntersection(Node* head1, Node* head2){
    if(head1 == nullptr || head2 == nullptr){
        return nullptr;
    }

    Node* tail1 = head1;
    int length1 = 1;
    while(tail1->next != nullptr){
        tail1 = tail1->next;
        length1++;
    }

    Node* tail2 = head2;
    int length2 = 1;
    while(tail2->next){
        tail2 = tail2->next;
        length2++;
    }

    // different tails, no intersection
    if(tail1 != tail2) return nullptr;

    // adjusting the starting point to be the same distance from the end
    Node* longer = length1 > length2 ? head1 : head2;
    Node* shorter = length1 > length2 ? head2 : head1;

    int difference = abs(length1 - length2);
    while(difference--){
        longer = longer->next;
    }

    // finding intersection, i.e. longer == shorter
    while(longer != shorter){
        longer = longer->next;
        shorter = shorter->next;
    }

    return longer ? shorter : nullptr; // or longer ? longer : nullptr or shorter ? shorter ? nullptr;
}

void breakIntersection(Node* head1, Node* head2){
    int length1 = 1;
    int length2 = 1;

    Node* walkerNode1 = head1;
    while(walkerNode1){
        walkerNode1 = walkerNode1->next;
        length1++;
    }

    Node* walkerNode2 = head2;
    while (walkerNode2)
    {
        walkerNode2 = walkerNode2->next;
        length2++;
    }

    Node* longer = length1 > length2 ? head1 : head2;
    Node* shorter = length1 > length2 ? head2 : head1;

    int difference = abs(length1 - length2);
    while(difference--){
        longer = longer->next;
    }

    // traversing to the node just before the common node
    while(longer->next != shorter->next){
        longer = longer->next;
        shorter = shorter->next;
    }

    // breaking the intersection
    longer->next = nullptr;
}

int main() {
    system("cls");
    LinkedList list1;
    LinkedList list2;

    int input1, input2;
    // cin >> nodes1 >> nodes2;
    cin >> input1;
    while(input1 != -1){
        list1.createNode(input1);
        cin >> input1;
    }

    cin >> input2;
    while(input2 != -1){
        list2.createNode(input2);
        cin >> input2;
    }

    int interPoint1, interPoint2;
    cin >> interPoint1 >> interPoint2;

    intersectList(list1.getHead(), list2.getHead(), interPoint1, interPoint2);

    list1.printList();
    list2.printList();

    // cout << boolalpha;
    // cout << hasIntersectionBrute(list1.getHead(), list2.getHead()) << endl;
    if(hasIntersection(list1.getHead(), list2.getHead())){
        breakIntersection(list1.getHead(), list2.getHead());
    }
    hasIntersection(list1.getHead(), list2.getHead()) ? cout << "true" << endl : 
        cout << "false" << endl;
        
    // cout << hasIntersection(list1.getHead(), list2.getHead())->data << endl;
    

    return 0;
}
