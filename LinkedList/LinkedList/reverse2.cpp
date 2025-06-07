#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;

	Node(int value) : data(value), next(nullptr) {}
};

class LinkedList{
	private:
		Node* head;
		Node* tail;
	public:
		LinkedList() : head(nullptr), tail(nullptr) {}

        Node* getHead(){
            return head;
        }
		
		void createNode(int value){
			// creating the Node
			Node* newNode = new Node(value);
			
			// if list is not empty
			if(head){
				tail->next = newNode;
				tail = newNode;
			}
			else
				head = tail = newNode;
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
		
		~LinkedList(){
			Node* walkerNode = head;
			Node* nextNode = nullptr;
				
			while(walkerNode){
				nextNode = walkerNode->next;
				delete walkerNode;
				walkerNode = nextNode;
			}
			head = nullptr;
            tail = nullptr;
		}
    
        Node* reverse(Node* start, Node* end) {
            Node* curr = start;
            Node* prev = nullptr;
            Node* nextNode = nullptr;
            while (curr != end) {
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
            return prev;  // `prev` becomes the new head of the reversed sublist
        }

        void reverseSublist(int left, int right) {
            if (left == right) return;  // No need to reverse if the range is the same

            // Step 1: Find the left node and its previous node
            Node* leftPrev = nullptr;
            Node* leftHead = head;

            for (int i = 1; i < left && leftHead != nullptr; i++) {
                leftPrev = leftHead;
                leftHead = leftHead->next;
            }

            // Step 2: Find the right node and its next node
            Node* rightHead = leftHead;
            Node* rightNext = nullptr;

            for (int i = left; i < right && rightHead != nullptr; i++) {
                rightHead = rightHead->next;
            }

            if (rightHead) {
                rightNext = rightHead->next;
            }

            // Step 3: Reverse the sublist from leftHead to rightHead
            Node* newNext = reverse(leftHead, rightNext);

            // Step 4: Reconnect the sublist
            if (leftPrev) {
                leftPrev->next = newNext;  // Reconnect the left side of the list
            } else {
                head = newNext;  // If reversing starts from the head, update the head
            }

            // Step 5: Reconnect the end of the reversed sublist
            leftHead->next = rightNext;
        }
};



int main(){
    system("cls");
    LinkedList list;

    int input;
    cin >> input;
    while(input != -1){
        list.createNode(input);
        cin >> input;
    }
    int left, right;
    cin >> left >> right;

    list.reverseSublist(left, right);
    list.printList();
	
	return 0;
}