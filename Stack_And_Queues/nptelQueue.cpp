#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, capacity;
    int* arr;
public:
    // Constructor to initialize the queue
    Queue(int N) {
        capacity = N + 1;  // Adjusting capacity for circular queue (one space to differentiate full and empty)
        arr = new int[capacity];  
        front = rear = 0;
    }

    // Function to return the size of the queue
    int queueSize() {
        return (capacity + rear - front) % capacity;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == rear);
    }

    // Function to get the front element of the queue
    int frontElement() {
        if (isEmpty()) {
            throw runtime_error("QueueEmptyException");
        }
        return arr[front];
    }

    // Function to dequeue an element from the front
    void dequeue() {
        if (isEmpty()) {
            throw runtime_error("QueueEmptyException");
        }
        front = (front + 1) % capacity;
    }

    // Function to enqueue an element to the rear
    void enqueue(int value) {
        if (queueSize() == capacity - 1) {
            throw runtime_error("QueueFullException");
        }
        arr[rear] = value;
        rear = (rear + 1) % capacity;
    }

    // Function to print the queue elements
    void printQueue() {
        if (!isEmpty()) {
            int i = front;
            while (i != rear) {
                cout << arr[i] << " ";
                i = (i + 1) % capacity;
            }
            cout << endl;
        } else {
            cout << "Queue is empty." << endl;
        }
    }

    // Destructor to clean up dynamically allocated memory
    ~Queue() {
        delete[] arr;
    }
};

int main() {
    system("cls");
    int size;  // Define the capacity of the queue
    cout << "Enter size: ";
    cin >> size;  // Get size input from the user
    Queue q(size);

    try {
        int input;
        // cout << "Enter elements to enqueue (-1 to stop): ";
        cin >> input;

        while (input != -1) {
            q.enqueue(input);
            cin >> input;
        }

        cout << "Queue Size: " << q.queueSize() << endl;
        q.printQueue();

        q.dequeue();
        cout << "After dequeue, Queue is: ";
        q.printQueue();
        cout << "Queue size: " << q.queueSize() << endl;

    } catch (const exception &e) {
        cout << e.what() << endl;
    }

    return 0;
}
