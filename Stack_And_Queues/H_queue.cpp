#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);
    }

    void dequeue() {
        if (s1.empty() && s2.empty())
            throw runtime_error("Queue is Empty");

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
    }

    int front() {
        if (s1.empty() && s2.empty())
            throw runtime_error("Queue is Empty");

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    system("cls");

    Queue q;
    int N;
    cin >> N;

    while (N--) {
        try {
            string op;
            cin >> op;

            if (op == "enqueue") {
                int input;
                cin >> input;
                q.enqueue(input);
            } else if (op == "dequeue") {
                q.dequeue();
            } else if (op == "front") {
                cout << q.front() << endl;
            } else if (op == "isEmpty") {
                cout << boolalpha << q.isEmpty() << endl;
            }
        } catch (const exception &e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}
