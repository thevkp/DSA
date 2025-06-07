#include <iostream>
// #include <crtdbg.h>
using namespace std;


struct Node{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}     
};

void append(Node* head, int value){
    Node* newNode = new Node(value);

    Node* walkerNode = head;
    while(walkerNode->next){    
        walkerNode = walkerNode->next;
    }

    walkerNode->next = newNode;
}


void printList(Node* head){
    if(!head){
        cout << "NULL" << endl;
        return;
    }
    Node* walkerNode = head;

    while(walkerNode){
        cout << walkerNode->data << " ";
        walkerNode = walkerNode->next;
    }
    cout << "NULL" << endl;
}

Node* deleteList(Node* head){
    Node* curr = head;
    Node* nextNode = nullptr;

    while(curr){
        nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }

    return nullptr;
}


Node* headShot(Node* head){
    if(!head) return head;

    Node* temp = head;
    head = head->next;
    delete temp;

    return head;
}

Node* backShot(Node* head){
    if(!head) return nullptr;

    if(!head->next){
        delete head;
        return nullptr;
    }

    Node* walkerNode = head;
    while(walkerNode->next && walkerNode->next->next){
        walkerNode = walkerNode->next;
    }

    delete walkerNode->next;
    walkerNode->next = nullptr;

    return head;
}



int main(){
    system("cls");

    Node* head = new Node(-1);

    // cout << head->data << endl;

    // Node* current = new Node(1);
    // head->next = current;

    // cout << head->data << " " << head->next->data << endl;

    // current = new Node(2);
    // head->next->next = current;

    // cout << head->next->next->data << endl;

    int input;
    cin >> input;

    while(input != -1){
        append(head, input);
        cin >> input;
    }



    Node* temp = head;
    head = head->next;
    delete(temp);
    printList(head);


    // head = deleteList(head);
    while(head){
        head = headShot(head);
    }
    printList(head);
    return 0;
}
