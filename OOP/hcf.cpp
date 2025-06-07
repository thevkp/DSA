#include <iostream>
#include <cstdlib>
using namespace std;

// Function to calculate the HCF (GCD) using the Euclidean algorithm
int hcf(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    system("cls");
    int num1, num2;
    
    // Input two numbers
    // cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Calculate and display the HCF
    int result = hcf(num1, num2);
    // cout << "The HCF of " << num1 << " and " << num2 << " is " << result << endl;
    cout << result << endl;

    return 0;
}
