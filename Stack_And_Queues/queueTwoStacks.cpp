#include <iostream>
using namespace std;


class TwoStacks{
    private:
        int top1, top2, capacity;
        int stack1Size, stack2Size;
        int* arr;

        bool isEmpty1(){
            return top1 == -1;
        }

        bool isEmpty2(){
            return top2 == capacity;
        }

        bool isFull1(){
            return top1 + 1 == top2;
        }

        bool isFull2(){
            return top2 - 1 == top1;
        }

        void push1(int value){
            if(isFull1()){
                throw runtime_error("Stack1Overflow");
            }

            arr[++top1] = value;
            stack1Size += 1;
        }

        void push2(int value){
            if(isFull2()){
                throw runtime_error("Stack2Overflow");
            }

            arr[--top2] = value;
            stack2Size += 1;
        }

        int pop1(){
            if(isEmpty1()){
                throw runtime_error("Stack1Underflow");
            }

            return arr[top1--];
            stack1Size -= 1;
        }


        void pop2(){
            if(isEmpty2()){
                throw runtime_error("Stack2Underflow");
            }

            top2++;
            stack2Size -= 1;
        }

        int size1(){
            return stack1Size;
        }
    public:
        TwoStacks(int n){
            capacity = n;
            top1 = -1;
            top2 = capacity;
            stack1Size = stack2Size = 0;
            arr = new int[capacity];
        }

        ~TwoStacks(){
            delete[] arr;
        }

        void enqueue(int value){
            push1(value);
        }

        void dequeue(){
            if(isEmpty1() && isEmpty2()){
                throw runtime_error("StackUnderflow");
            }

            while(!isEmpty1()){
                push2(arr[top1--]);
            }

            top2++;
        }

        int front(){
            if(isEmpty1() && isEmpty2()){
                throw runtime_error("StackUnderflow");
            }

            while(!isEmpty1()){
                push2(arr[top1--]);
            }

            return arr[top2--];
        }

        bool isEmpty(){
            return isEmpty1() && isEmpty2();
        }

};



int main(){
    system("cls");

    int N;
    cin >> N;

    while(N--){
        int n;
        cin >> n;

        TwoStacks q(n);

        try{
            string op;
            cin >> op;

            if(op == "enqueue"){
                int input;
                cin >> input;

                q.enqueue(input);
            }
            else if(op == "dequeue"){
                q.dequeue();
            }
            else if(op == "front"){
                cout << q.front() << endl;
            }
            else if(op == "isEmpty"){
                cout << boolalpha;
                cout << q.isEmpty() << endl;
            }
        }
            catch(const exception& e){
            cout << e.what() << endl;
        }
    }




    return 0;
}