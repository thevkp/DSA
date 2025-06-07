#include <iostream>
using namespace std;

class DLL {
    private:
        struct Node {
            Node* prev;
            int data;
            Node* next;

            Node(int value) : prev(nullptr), data(value), next(nullptr) {}
        };

        Node* head;

    public:
        DLL() : head(nullptr) {}

        ~DLL() {
            while (head) {
                headShot();
            }
        }

        void firstImpression(int value) {
            Node* newNode = new Node(value);

            if (!head) {
                head = newNode;
                return;
            }

            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        void backPack(int value) {
            if (!head) {
                firstImpression(value);
                return;
            }

            Node* newNode = new Node(value);

            Node* walkerNode = head;
            while (walkerNode->next) {
                walkerNode = walkerNode->next;
            }

            walkerNode->next = newNode;
            newNode->prev = walkerNode;
        }

        void headShot() {
            if (!head) return;

            Node* temp = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }
            delete temp;
        }

        void backShot() {
            if (!head) return;

            if (!head->next) {
                headShot();
                return;
            }

            Node* walkerNode = head;
            while (walkerNode->next) {
                walkerNode = walkerNode->next;
            }

            walkerNode->prev->next = nullptr;
            delete walkerNode;
        }

        void printList() {
            Node* walkerNode = head;

            while (walkerNode) {
                cout << walkerNode->data << " ";
                walkerNode = walkerNode->next;
            }
            cout << "-1" << endl;
        }
};

int main() {
    system("cls");

    DLL list;

    int input;
    cin >> input;

    while (input != -1) {
        list.firstImpression(input);
        cin >> input;
    }

    cin >> input;
    while (input != -1) {
        list.backPack(input);
        cin >> input;
    }

    list.printList();

    return 0;
}
