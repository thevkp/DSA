#include <iostream>
using namespace std;

int fill_array(double arr[], int limit) {
    double temp;
    int i;
    cout << "Enter values separated by space: ";
    for (i = 0; i < limit; i++) {
        // cout << "Enter value #" << (i + 1) << ": "; // Optional prompt
        cin >> temp;
        if (!cin) {    // bad input
            cin.clear(); // Clear error flags
            while (cin.get() != '\n') // Discard invalid input
                continue;
            cout << "Bad input; input process terminated.\n"; // Optional message
            break;
        } else if (temp < 0) { // signal to terminate
            cout << "Negative value encountered; input process terminated.\n"; // Optional message
            break;
        }
        arr[i] = temp;
    }
    return i;
}

void printArray(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    system("cls");
    int size;
    cout << "Enter the size of the array: "; // Prompt for array size
    cin >> size;

    if (size <= 0) { // Check for invalid size
        cout << "Size must be positive!" << endl;
        return 1; // Return error code
    }

    double* arr = new (nothrow) double[size]; // Use nothrow to handle allocation failure

    if (arr == nullptr) { // Check if allocation was successful
        cout << "Memory allocation failed!" << endl;
        return 1; // Return error code
    }

    int length = fill_array(arr, size);
    cout << "Number of values entered: " << length << endl;

    printArray(arr, length);

    delete[] arr; // Deallocate memory
    return 0;
}
