#include <iostream>
#include <stdexcept>
using namespace std;

class TwoStacks {
private:
    int top1, top2, capacity, size1, size2;
    int* arr;

public:
    TwoStacks(int n) {
        capacity = n;
        top1 = -1;
        top2 = capacity;
        size1 = size2 = 0;
        arr = new int[capacity];
    }

    ~TwoStacks() {
        delete[] arr;
    }

    bool isFull1() {
        return top1 + 1 == top2;
    }

    bool isFull2() {
        return top2 - 1 == top1;
    }

    bool isEmpty1() {
        return top1 == -1;
    }

    bool isEmpty2() {
        return top2 == capacity;
    }

    void push1(int value) {
        if (isFull1()) {
            throw runtime_error("Stack1 Overflow");
        }
        arr[++top1] = value;
        size1++;
    }

    void push2(int value) {
        if (isFull2()) {
            throw runtime_error("Stack2 Overflow");
        }
        arr[--top2] = value;
        size2++;
    }

    int pop1() {
        if (isEmpty1()) {
            throw runtime_error("Stack1 Underflow");
        }
        size1--;
        return arr[top1--];
    }

    int pop2() {
        if (isEmpty2()) {
            throw runtime_error("Stack2 Underflow");
        }
        size2--;
        return arr[top2++];
    }

    int peek1() {
        if (isEmpty1()) {
            throw runtime_error("Stack1 Underflow");
        }
        return arr[top1];
    }

    int peek2() {
        if (isEmpty2()) {
            throw runtime_error("Stack2 Underflow");
        }
        return arr[top2];
    }

    int getSize1() {
        return size1;
    }

    int getSize2() {
        return size2;
    }
};

int main() {
    TwoStacks st(10);

    try {
        st.push1(1);
        st.push1(2);
        st.push1(3);
        st.push2(10);
        st.push2(9);
        st.push2(8);

        cout << st.peek1() << endl;
        cout << st.peek2() << endl;

        cout << st.pop1() << endl;
        cout << st.pop2() << endl;

        cout << st.getSize1() << endl;
        cout << st.getSize2() << endl;
    } 
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
