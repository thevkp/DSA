#include <iostream>
using namespace std;


class stack {
    private:
        int capacity;
        int top;
        int* arr;
    public:
        stack(int n) {
            capacity = n;
            top = -1;
            arr = new int[capacity];
        }

        ~stack(){
            delete[] arr;
        }

        bool isFull(){
            return top == capacity - 1;
        }

        bool isEmpty(){
            return top == -1;
        }

        int size(){
            return top + 1;
        }

        void push(int value){
            if(isFull()){
                cout << "Stack Overflow" << endl;
                return;
            }

            arr[++top] = value;
        }

        void pop(){
            if(isEmpty()){
                cout << "Stack underflow: ";
                return;
            }

            top--;
        }

        int peek(){
            if(isEmpty()){
                cout << "Stack Underflow: ";
                return -1;
            }

            return arr[top];
        }
};


int main(){ 
    system("cls");

    // int n;
    // cin >> n;

    stack st(5);
    
    cout << st.size() << endl;
    cout << st.peek() << endl;

    return 0;
}