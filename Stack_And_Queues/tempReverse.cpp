#include <stack>
#include <iostream>
using namespace std;

void reverseStack(stack<int>& s) {
    stack<int> temp;

    // Transfer all elements from s to temp, reversing the order
    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }

    // Transfer elements back to the original stack (reversed order)
    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }
}

int main() {
    stack<int> s;
    s.push(12);
    s.push(34);
    s.push(56);

    // Print original stack
    cout << "Original stack (before reversing): ";
    stack<int> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // Reverse the stack
    reverseStack(s);

    // Print reversed stack
    cout << "Reversed stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
