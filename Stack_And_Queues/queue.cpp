#include <iostream>
using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int capacity;
        int* arr;
    public:
        Queue(int size){
            capacity = size;
            front = rear = -1;
            arr = new int[capacity];
        }

        bool isEmpty(){
            return front == -1 || rear == -1;
        }

        bool isFull(){
            return (rear + 1) % capacity == front;
        }

        void enqueue(int value){
            if(isFull()){
                cout << "Queue overflow." << endl;
                return;
            }

            if(isEmpty()){
                front = 0;
            }
            rear = (rear + 1) % capacity;
            arr[rear] = value;
        }

        void dequeue(){
            if(isEmpty()){
                cout << "Queue underflow." << endl;
                return;
            }

        }
};



int main(){


    return 0;
}