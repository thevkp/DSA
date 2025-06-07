#include <iostream>
using namespace std;

class Queue {
    int qfront, rear, capacity;
    int* arr;
public:
    // Constructor to initialize the queue with a given capacity
    Queue(int N) {
        capacity = N + 1;
        arr = new int[capacity];
        qfront = rear = 0;
    }

    // Destructor to free dynamically allocated memory
    ~Queue() {
        delete[] arr;
    }

    // Function to return the current size of the queue
    int size() {
        return (capacity + rear - qfront) % capacity;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return qfront == rear;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % capacity == qfront;
    }

    // Function to add an element to the queue
    void enqueue(int data) {
        if (isFull()) {
            throw runtime_error("QueueFullException");
        }

        arr[rear] = data;
        rear = (rear + 1) % capacity;
    }

    // Function to remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            throw runtime_error("QueueEmptyException");
        }

        int value = arr[qfront];
        qfront = (qfront + 1) % capacity;
        return value;
    }

    // Function to get the front element of the queue
    int front() {
        if (isEmpty()) {
            return -1;
        }
        return arr[qfront];
    }
};

int main() {
    system("cls");

    int size;
    cout << "Enter the size: ";
    cin >> size;

    Queue q(size);  // Provide the queue size

    try {
        int input;
        // cout << "Enter elements to enqueue (-1 to stop): ";
        cin >> input;
        while (input != -1) {
            q.enqueue(input);
            cin >> input;
        }

        cout << "No. of element: " << q.size() << endl;

        cout << "Dequeuing elements: ";
        int i = q.size();
        while (i > 0) {
            cout << q.dequeue() << " ";
            i--;
        }
        cout << endl;

        cout << "No. of elements: " << q.size() << endl;
        cout << q.dequeue() << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
