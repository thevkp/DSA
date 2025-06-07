#include <iostream>
using namespace std;

class Stack{
    private:
        int top;
        int capacity;
        int* arr;
    public:
        Stack(int N){
            this->capacity = N;
            top = -1;
            arr = new int[capacity];
        }

        // dealloacating the dynamically allocated memory
        ~Stack(){
            delete[] arr;
        }

        // get the number of elements
        int size(){
            return (top + 1);
        }

        // function to check if stack is empty
        bool isEmpty(){
            return top == -1;
        }
        
        // function to check if stack is full
        bool isFull(){
            return top == capacity - 1;
        }

        // adding elements to the stack
        void push(int value){
            if(isFull())
                throw runtime_error("Stack Overflow");
            
            arr[++top] = value;
        }

        // removing elements
        int pop(){
            if(isEmpty())
                throw runtime_error("Stack Underflow");

            return arr[top--];
        }

        // get the top element withou removing it
        int peek(){
            if(isEmpty())
                throw runtime_error("Stack Underflow");

            return arr[top];
        }

        void printStack(){
            if(!isEmpty()){
                for(int i = 0; i < size(); i++){
                cout << arr[i] << " ";
                }
            }
            else{
                cout << "Stack is empty." << endl;
                return;
            }
            cout << endl;
        }
};

int main(){
    system("cls");
    int N;
    cout << "Number of elements: ";
    cin >> N;

    Stack stack(N);
    try{
        int input;
        cin >> input;
        while(input != -1){
            stack.push(input);
            cin >> input;
        }

        cout << "Size: " << stack.size() << endl;
        stack.printStack();

        int delEls;
        cout << "Enter the number of elements to be popped: ";
        cin >> delEls;
        for(int i = 0; i < delEls; i++){
            cout << stack.pop() << " ";
        }
        cout << endl;

        cout << "Size: " << stack.size() << endl;
    }
    catch(const exception& e){
        cout << e.what() << endl;
    }

    return 0;
}