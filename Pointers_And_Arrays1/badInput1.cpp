#include <iostream> // Include the necessary library for input/output

int fill_array(double ar[], int limit) {
    using namespace std; // Use the standard namespace for convenience
    double temp; // Temporary variable to store user input
    int i; // Loop counter and element count

    for (i = 0; i < limit; i++) {
        cout << "Enter value #" << (i + 1) << ": "; // Prompt user for input
        cin >> temp; // Read input into temp variable

        if (!cin) { // Check if input is invalid
            cin.clear(); // Clear the error state of cin
            while (cin.get() != '\n') // Discard invalid input until newline
                continue;
            cout << "Bad input; input process terminated.\n";
            break; // Exit the loop on bad input
        } else if (temp < 0) { // Check for negative input as a termination signal
            break; // Exit the loop on negative input
        }

        ar[i] = temp; // Store the valid input in the array
    }

    return i; // Return the number of successfully filled elements
}

// Example usage of the fill_array function
int main() {
    const int size = 10; // Define the size of the array
    double numbers[size]; // Declare an array of doubles
    int entered; // Variable to store the number of entered elements

    entered = fill_array(numbers, size); // Call fill_array and store the result

    std::cout << "You entered " << entered << " values:\n";
    for (int i = 0; i < entered; i++) {
        std::cout << numbers[i] << " "; // Output the values entered
    }
    std::cout << std::endl;

    return 0;
}
