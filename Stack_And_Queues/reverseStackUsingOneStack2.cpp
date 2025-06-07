#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of a stack
void insertAtBottom(stack<int>& s, int x) {
    if (s.empty()) {
        s.push(x);
        return;
    }

    int temp = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(temp);
}

// Function to reverse the stack using recursion
void reverseStack(stack<int>& s) {
    if (s.empty())
        return;

    int temp = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, temp);
}

// Helper function to print the stack without modifying it
void printStack(stack<int> s) { // Pass by value to keep original stack unchanged
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(12);
    s.push(34);
    s.push(56);

    cout << "Original stack (top to bottom): ";
    printStack(s); // Output: 56 34 12 

    reverseStack(s);

    cout << "Reversed stack (top to bottom): ";
    printStack(s); // Output: 12 34 56 

    return 0;
}
