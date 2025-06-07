#include <iostream>
using namespace std;

class Queue{
    private:
        int front, rear, capacity;
        int* arr;
    public:
        Queue(int size) : front(0), rear(0), capacity(size){
            arr = new int[capacity];
        }

        ~Queue(){
            delete[] arr;
        }

        // function to calculate the size of the queue
        int queueSize(){
            return (capacity + rear - front) % capacity;
        }

        // funciton to check if queue is full
        bool isFull(){
            return queueSize() == capacity - 1;
        }

        // function to check if queue is empty
        bool isEmpty(){
            return front == rear;
        }

        // funciton enqueue elements
        void enqueue(int value){
            if(isFull())
                throw runtime_error("QueueFullException");
            
            arr[rear] = value;
            rear = (rear + 1) % capacity;
        }

        // function to get first element without deleting
        int peek(){
            if(isEmpty())
                throw runtime_error("QueueEmptyException");
            
            return arr[front];
        }

        // function to dequeue elements
        void dequeue(){
            if(isEmpty())
                throw runtime_error("QueueEmptyException");

            arr[front] = -1; // set queue element to null
            front = (front + 1) % capacity;
        }

        // function to print queue
        void printQueue(){
            if(!isEmpty()){
                int i = front;
                while(i != rear){
                    cout << arr[i] << " ";
                    i = (i + 1) % capacity;
                }
                cout << endl;
            }
            else    
                cout << "List is empty." << endl;
        }
};

int main(){
    int N;
    cout << "Enter N: ";
    cin >> N;

    Queue q(N);
    try{
        int input;
        cin >> input;
        while(input != -1){
            q.enqueue(input);
            cin >> input;
        }

        q.printQueue();
        cout << "Size: " << q.queueSize() << endl;
    }
    catch(const exception& e){
        cout << e.what() << endl;
    }


    return 0;
}