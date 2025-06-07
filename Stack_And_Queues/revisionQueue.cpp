#include <iostream>
using namespace std;


class Queue{
    private:
        int capacity;
        int front, rear;
        int* arr = nullptr;
    public:
        Queue(int N){
            this->capacity = N;
            front = rear = -1;
            arr = new int[capacity];
        }

        ~Queue(){
            delete[] arr;
        }

        bool isEmpty(){
            return (front == rear);
        }
};



int main(){
    system("cls");


    return 0;
}