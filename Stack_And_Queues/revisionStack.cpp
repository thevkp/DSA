#include <iostream>
using namespace std;

class Stack{
    private:
        int capacity;
        int top;
        int* arr = nullptr;
    public:
        Stack(int n){
            this->capacity = n;
            top = -1;
            arr = new int[capacity];
        }

        ~Stack(){
            delete[] arr;
        }

        bool isEmpty(){
            return top == -1;
        }

        bool isFull(){
            return top == capacity - 1;
        }

        int size(){
            return (top + 1);
        }

        void push(int value){
            if(isFull()){
                throw runtime_error("StackOverflow");
            }

            arr[++top] = value;
        }

        void pop(){
            if(isEmpty()){
                throw runtime_error("StackUnderflow");
            }

            top = top - 1;
        }

        int peek(){
            if(isEmpty())
                throw runtime_error("StackUnderflow");

            return arr[top--];
        }

};


int main(){
    system("cls");
    int capacity;
    cin >> capacity;

    Stack st(capacity);

    try{
        int input;
        cin >> input;
        while(input != -1){
            st.push(input);
            cin >> input;
        }
    }
    catch(const exception &e){
        cout << e.what() << endl;
    }

    cout << st.size() << endl;

    return 0;
}