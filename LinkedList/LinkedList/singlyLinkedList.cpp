#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* link;
};

Node* addToBeg(Node* head, int value){
    // creating the node
    Node* temp = new Node();
    temp -> data = value;
    temp->link = nullptr;

    // linking to the beginning of the list
    temp->link = head;
    head = temp;

    return head;
}

Node* addToEnd(Node* head, int value){
    // creating the node
    Node* temp = new Node();
    temp->data = value;
    temp->link = nullptr;

    // traversing to the end of the list
    Node* ptr = head;
    while(ptr->link != nullptr){
        ptr = ptr->link;
    }

    // linking the Node
    ptr->link = temp;

    return head;
}


void printList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";  // Print data followed by a space
        temp = temp->link;
    }
    cout << endl;  // Move to the next line after printing all nodes
}



Node* deleteList(Node* head) {
    Node* temp;
    while (head != nullptr) {
        temp = head->link;  // Save the next node
        delete head;        // Delete the current node
        head = temp;        // Move to the next node
    }
    return nullptr;  // Return nullptr since the list is now empty
}

int main(){
    Node* head = nullptr;
    head = new Node();

    head->data = 1;
    head->link = nullptr;

    head = addToBeg(head, 2);
    head = addToBeg(head, 3);
    head = addToEnd(head, 4);


    // head->data = 1;
    // head->link =  nullptr;

    printList(head);

    head = deleteList(head);
    return 0;
}