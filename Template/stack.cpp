#include <iostream>
using namespace std;

template<typename T>

class Stack{
    private:
        int top;
        int capacity;
        int stSize;
        T* arr;
    public:
        Stack(T size){
            capacity = size;
            top = -1;
            arr = new T[capacity];
            stSize = 0;
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

        void push(T value){
            if(isFull()){
                throw runtime_error("Stack Overflow");
            }

            arr[++top] = value;
            stSize++;
        }

        T peek(){
            if(isEmpty()){
                throw runtime_error("Stack Empty");
            }

            return arr[top--];
        }

        void pop(){
            if(isEmpty()){
                throw runtime_error("Stack Underflow");
            }

            top--;
            stSize--;
        }

        size_t size(){
            return stSize;
        }
};




int main(){
    system("cls");

    Stack<int> st(5);
    Stack<char> stc(3);

    try{
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(5);
        // st.push(6);

        cout << st.peek() << endl;
        cout << st.size() << endl;
        cout << (st.size() == 5) << endl;
    }
    catch(const exception& e){
        cout << e.what() << endl;
    }

    try{
        stc.push('a');
        stc.push('b');
        stc.push('c');

        cout << stc.peek() << endl;
        cout << stc.peek() << endl;
        cout << stc.size() << endl;
    }
    catch(const exception& e){
        cout << e.what() << endl;
    }


    return 0;
}