#include <iostream>
#include <vector>
using namespace std;

class TwoStacks {
private:
    int top1, top2, capacity;
    int stack1Size, stack2Size;
    vector<int> arr;

    bool isEmpty1() {
        return top1 == -1;
    }

    bool isEmpty2() {
        return top2 == capacity;
    }

    bool isFull1() {
        return top1 + 1 == top2;
    }

    bool isFull2() {
        return top2 - 1 == top1;
    }

    void push1(int value) {
        if (isFull1()) {
            throw runtime_error("Stack1Overflow");
        }
        arr[++top1] = value;
        stack1Size++;
    }

    void push2(int value) {
        if (isFull2()) {
            throw runtime_error("Stack2Overflow");
        }
        arr[--top2] = value;
        stack2Size++;
    }

    int pop1() {
        if (isEmpty1()) {
            throw runtime_error("Stack1Underflow");
        }
        stack1Size--;
        return arr[top1--];
    }

    int pop2() {
        if (isEmpty2()) {
            throw runtime_error("Stack2Underflow");
        }
        stack2Size--;
        return arr[top2++];
    }

public:
    TwoStacks(int size = 5) {
        capacity = size;
        arr = vector<int>(capacity);
        top1 = -1;
        top2 = capacity;
        stack1Size = stack2Size = 0;
    }

    void enqueue(int value) {
        push1(value);
    }

    void dequeue() {
        if (isEmpty1() && isEmpty2()) {
            throw runtime_error("StackUnderflow");
        }

        if (isEmpty2()) {
            while (!isEmpty1()) {
                push2(pop1());
            }
        }

        pop2();
    }

    int front() {
        if (isEmpty1() && isEmpty2()) {
            throw runtime_error("StackUnderflow");
        }

        if (isEmpty2()) {
            while (!isEmpty1()) {
                push2(pop1());
            }
        }

        return arr[top2];
    }

    bool isEmpty() {
        return isEmpty1() && isEmpty2();
    }
};

int main() {
    system("cls");

    TwoStacks q;

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
                cout << q.front() << endl;
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
