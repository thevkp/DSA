#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Node{
    private:
        int data;
        Node* link;
    public:
        Node() : link(nullptr){}


        void creatNode(Node*& head, Node*& tail, int value){
            Node* newNode = new Node();
            newNode->data = value;
            newNode->link = nullptr;

            if(head){
                tail->link = newNode;
                tail = newNode;
            }
            else{
                head = newNode;
                tail = newNode;
            }
        }

        bool checkPalindrome(Node* head){
            vector<int> arr;
            Node* walkerNode = head;
            while(walkerNode){
                arr.push_back(walkerNode->data);
                walkerNode = walkerNode->link;
            }

            int start = 0;
            int end = arr.size() - 1;
            while(start < end){
                if(arr[start] != arr[end])
                    return false;
                
                start++;
                end--;
            }

            return true;
        }

        void fixList(Node*& slow, Node*& head){
            Node* curr = head;
            Node* prev = nullptr;
            while(curr){
                Node* nextNode = curr->link;
                curr->link = prev;
                prev = curr;
                curr = nextNode;
            }

            head = prev;
            slow->link = head;
        }

        bool isPalindrome(Node* head){
            Node* turtle = head;
            Node* hare = head;
            while(hare && hare->link){
                turtle = turtle->link;
                hare = hare->link->link;
            }

            Node* curr = turtle;
            Node* prev = nullptr;
            while(curr){
                Node* nextNode = curr->link;
                curr->link = prev;
                prev = curr;
                curr = nextNode;
            }


            Node* start = head;
            Node* end = prev;
            while(start != end){
                if(start->data != end->data)
                    return false;
                start = start->link;
                end = end->link;
            }

            // fixList(turtle, prev);

            return true;
        }
        // void addToEmpty(Node*& head, int value){
        //     // checking if list is really empty
        //     if(head != nullptr){
        //         return;
        //     }

        //     Node* newNode = new Node();
        //     newNode->data = value;
        //     newNode->link = nullptr;

        //     head = newNode;
        // }

        // void addAtBeg(Node*& head, int value){
        //     // if list is empty
        //     if(head == nullptr){
        //             addToEmpty(head, value);
        //     }
        //     Node* newNode = new Node();
        //     newNode->data = value;
        //     newNode->link = nullptr;

        //     // linking at the beginning
        //     newNode->link = head;
        //     head = newNode;
        // }

        // void addToEnd(Node* head, int value){
        //     Node* newNode = new Node();
        //     newNode->data = value;
        //     newNode->link = nullptr;

        //     // traversing to the end;
        //     Node* walkerNode = head;
        //     while(walkerNode->link != nullptr){
        //         walkerNode = walkerNode->link;
        //     }

        //     // linking
        //     walkerNode->link = newNode;
        // }

        void printList(Node* head){
            Node* walkerNode = head;
            while(walkerNode){
                cout << walkerNode->data << " ";
                walkerNode = walkerNode->link;
            }

            cout << endl;
        }
};

int main(){
    system("cls");
    Node list;
    Node* head = nullptr;
    Node* tail = nullptr;

    int nodes, input;
    cin >> nodes;
    for(int i = 0; i < nodes; i++){
        cin >> input;
        list.creatNode(head, tail, input);
    }

    list.printList(head);
    cout << boolalpha;
    cout << list.checkPalindrome(head) << endl;
    cout << list.isPalindrome(head) << endl;
    list.printList(head);
    return 0;
}