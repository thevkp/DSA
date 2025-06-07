#include <iostream>
using namespace std;

class Stack{
    private:
        int top;
        int capacity;
        int* arr;
    public:
        Stack(int size){
            capacity = size;
            top = -1;
            arr = new int[capacity];
        }

        ~Stack(){
            delete[] arr;
        }

        bool isFull(){
            return top == capacity - 1;
        }

        bool isEmpty(){
            return top == -1;
        }

        // pushing elements
        void push(int value){
            if(isFull()){
                cout << "Stack overflow." << endl;
                return;
            }

            arr[++top] = value;
        }

        // popping the elements
        void pop(){
            if(isEmpty()){
                cout << "Stack underflow." << endl;
                return;
            }
            top--;
        }

        // top element
        int peek(){
            if(isEmpty()){
                cout << "Stack underflow." << endl;
                return -1;
            }

            return arr[top];
        }
};

int main(){
    system("cls");
    int size;
    cin >> size;

    Stack stack(size);

    int input;
    for(int i = 0; i < size; i++){
        cin >> input;
        stack.push(input);
    }
    
    stack.pop();
    cout << stack.peek() << endl;

    return 0;
}