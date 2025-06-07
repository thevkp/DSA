#include <iostream>
using namespace std;


class Queue{
    private:
        int capacity;
        int front, rear;
        int* arr = nullptr;
    public:
        Queue(int N){
            capacity = N;
            front = rear = -1;
            arr = new int[capacity];
        }

        ~Queue(){
            delete[] arr;
        }

        bool isEmpty(){
            return front == -1;
        }

        bool isFull(){
            return rear + 1 >= capacity;
        }

        void dequeue(){
            if(isEmpty())
                throw runtime_error("QueueUnderflow");
            
            front = front + 1;
        }

        void enqueue(int value){
            if(isFull())
                throw runtime_error("QueueOverflow");

            if(front == rear){
                front = front + 1;
            }

            arr[++rear] = value;
        }

        int peek(){
            if(isEmpty())
                throw runtime_error("QueueEmpty");
            
            if(front > rear)
                front = rear = -1;

            return arr[front++];
        }
        
};


int main(){
    system("cls");

    int capacity;
    cin >> capacity;

    Queue q(capacity);

    try{
        int input;
        cin >> input;

        while(input != -1){
            q.enqueue(input);
            cin >> input;
        }


    }
    catch(const exception& e){
        cout << e.what() << endl;
    }



    return 0;
}