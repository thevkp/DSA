#include <iostream>
using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int capacity;
        int* arr;
    public:
        Queue(int size) : capacity(size){
            front = rear = -1;
            arr = new int[capacity];
        }

        ~Queue(){
            delete[] arr;
        }

        int size(){
            if(front == -1) return 0;
            return(rear >= front) ? (rear - front + 1) : (capacity - front + rear + 1);
        }
        
        // works well if front and rear are initialized with 0;
        // int size(){
        //     // if(front == -1) return 0;
        //     return (capacity + rear - front) % capacity;
        // }

        bool isFull(){
            return (rear + 1) % capacity == front;
        }

        bool isEmpty(){
            return front == -1;
        }

        void enqueue(int value){
            if(isFull()){
                cout << "Queue overFlow." << endl;
                return;
            }

            if(!isEmpty()){
                rear = (rear + 1) % capacity;
            }
            else
                front = rear = 0;

            arr[rear] = value;
        }

        void dequeue(){
            if(isEmpty()){
                cout << "Queue underflow." << endl;
                return;   
            }

            if(front == rear){
                front = rear = -1;
            }
            else
                front = (front + 1) % capacity;
        }

        int getFront(){
            return front;
        }
        int getRear(){
            return rear;
        }

        void printQueue() {
            if (isEmpty()) {
                cout << "Queue is empty!" << endl;
                return;
            }

            cout << "Queue elements: ";
            int i = front;
            while (i != rear) {
                cout << arr[i] << " ";
                i = (i + 1) % capacity;
            }
            cout << arr[rear] << endl; // Print the last element
        }
};


int main(){
    int size = 5;
    int input;

    Queue q(size);

    cin >> input;
    while(size-- && input != -1){
        q.enqueue(input);
        cin >> input;
    }

    q.printQueue();
    // q.dequeue();
    // q.dequeue();
    // cout << q.getFront() << endl;
    // cout << q.getRear() << endl;
    // q.dequeue();
    // q.dequeue();
    // q.dequeue();
    // cout << boolalpha;
    // cout << q.isEmpty() << endl;
    // cout << q.getFront() << endl;
    // cout << q.getRear() << endl;
    cout << q.size() << endl;


    return 0;
}