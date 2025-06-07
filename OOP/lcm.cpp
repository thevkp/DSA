#include <iostream>
using namespace std;

// Function to calculate the Greatest Common Divisor (GCD) using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the Least Common Multiple (LCM)
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int num1, num2;
    
    // Input two numbers
    // cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Calculate and display the LCM
    int result = lcm(num1, num2);
    // cout << "The LCM of " << num1 << " and " << num2 << " is " << result << endl;
    cout << result << endl;
    return 0;
}
