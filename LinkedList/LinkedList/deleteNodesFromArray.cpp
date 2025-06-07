#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class SLL{
    private:
        Node* head;
        int listSize;
    public:
    SLL(){
        head = nullptr;
        listSize = 0;
        // reverseList();
    }

    ~SLL(){
        deleteList();
    }

    void setHead(Node*& newHead){
        this->head = newHead;
    }

    Node* getHead(){
        return head;
    }

    void addToList(int value){
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;
    }

    void printList(){
        if(!head){
            cout << "List is empty." << endl;
            return;
        }

        Node* walkerNode = head;

        while(walkerNode){
            cout << walkerNode->data << " ";
            walkerNode = walkerNode->next;
        }
        cout << endl;
    }

    void reverseList(){
        Node* prev = nullptr;
        Node* curr = head;
        Node* nextNode = nullptr;

        while(curr){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        head = prev;
    }

    void deleteList(){
        Node* curr = head;
        Node* nextNode = nullptr;

        while(curr){
            nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }

        head = nullptr;
    }
};


void deleteNodeByValue(SLL& list, Node*& head, int value, int count){
    while(count--){
        if(head->data == value){
        Node* curr = head;
        head = head->next;
        delete curr;
        }

        Node* walkerNode = head;
        Node* prevNode = nullptr;
        while(walkerNode && walkerNode->data != value){
            prevNode = walkerNode;
            walkerNode = walkerNode->next;
        }

        if(walkerNode){
            prevNode->next = walkerNode->next;
            delete walkerNode;
        }

        list.setHead(head);
    }
}

int occurence(Node*& head, int value){
    Node* walkerNode = head;
    int count = 0;
    while(walkerNode){
        if(walkerNode->data == value)
            count++;
        walkerNode = walkerNode->next;
    }

    return count;
}



void deleteNodes(SLL& list, Node*& head, vector<int>& arr){
    for(int& num : arr){
        int count = occurence(head, num);
        deleteNodeByValue(list, head, num, count);
    } 
}



int main(){
    system("cls");

    SLL list;

    int input;
    cin >> input;

    while(input != -1){
        list.addToList(input);
        cin >> input;
    }

    vector<int> vec;

    cin >> input;
    while(input != -1){
        vec.push_back(input);
        cin >> input;
    }

    list.reverseList();
    list.printList();
    cout << list.getHead()->data << endl;

    Node* head = list.getHead();
    deleteNodes(list, head, vec);

    list.printList();

    return 0;
}