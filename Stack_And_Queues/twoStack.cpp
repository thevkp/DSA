#include <iostream>
using namespace std;

class Stack{
    private:
        int top1, top2, capacity;
        int* arr;
    public:
        Stack(int s){
            this->capacity = s;
            arr = new int[capacity];
            top1 = -1;
            top2 = capacity;
        }

        bool isFull1(){
            return (top1 == capacity - 1) && (top1 == top2 - 1);
        }

        bool isFull2(){
            return (top2 >= 0) && (top2 == top1 + 1);
            // return (top2 - top1 + 1 > 1);
        }

        // push in first stack
        void push1(int value){
            // if(top2 - top1 > 1){
            //     arr[++top1] = value;
            // }
            if(!isFull1())
                arr[++top1] = value;
            else    
                throw runtime_error("Stack1 Overflow");
        }

        // push in second stack
        void push2(int value){
            if(!isFull2())
                arr[--top2] = value;
            else    
                throw runtime_error("Stack2 Overflow");
        }

        // pop from Stack1
        int pop1(){
            if(!(top1 == -1))
                return arr[top1--];
            else    
                throw runtime_error("Stack1 underflwo");
        }

        // pop from Stack2
        int pop2(){
            if(!(top2 == capacity - 1))
                return arr[top2++];
            else    
                throw runtime_error("Stack2 underflow");
        }
};

int main(){
    system("cls");
    int N;
    cout << "Number of elements: ";
    cin >> N;

    Stack stack(N);

    try{
        int input, stVar;
        cout << "Enter 1 to push in stack1 and 2 to push in stack2: ";
        cin >> stVar;
        cout << "Enter elements(-1 to exit: )";
        cin >> input;

        while(input != -1){
            stVar == 1 ? stack.push1(input) : stack.push2(input);
            cin >> input;
        }
    }
    catch(const exception& e){
        cout << e.what() << endl;
    }


    return 0;
}