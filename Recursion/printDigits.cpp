#include <iostream>
using namespace std;

void printDigit(int n){
    if(n == 0) return;

    // cout << n % 10 << " "; // will print in reverse order
    printDigit(n / 10);
    cout << n % 10 << " ";
}

void printDigitVerbose(int n) {
    if(n == 0) return;
    
    cout << "Digit: " << n % 10 << endl;
    cout << "Remaining number: " << n / 10 << endl;
    printDigitVerbose(n / 10);
}

int numberOfDigits(int n){
    if(n == 0) return 0;

    return 1 + numberOfDigits(n / 10);
}

int sumOfDigits(int n){
    if(n == 0) return 0;

    return n % 10 + sumOfDigits(n / 10);
}

int sumOfEvenDigits(int n){
    if(n == 0) return 0;

    int digit = n % 10;
    int evenDigits = digit % 2 == 0 ? digit : 0;
    return evenDigits + sumOfEvenDigits(n / 10);
}

int sumOfOddDigits(int n){
    if(n == 0) return 0;

    int digit = n % 10;
    int oddDigits = digit % 2 == 0 ? 0 : digit;
    return oddDigits + sumOfOddDigits(n / 10);
}

bool isPrime(int digit){
    if(digit < 2) return false;

    for(int i = 1; i * i <= digit; i++) {
        if(digit % i == 0) return false;
    }

    return true;
}

int sumOfPrimeNumbers(int n){
    if(n == 0) return 0;
    
    int digit = n % 10;
    int primeDigits = isPrime(digit) ? digit : 0;

    return primeDigits + sumOfPrimeNumbers(n / 10); 
}

int main(){
    system("cls");

    int n;
    cin >> n;

    printDigit(n);
    cout << endl;
    printDigitVerbose(n);
    cout << endl;
    cout << numberOfDigits(n) << endl;
    cout << sumOfDigits(n) << endl;
    cout << sumOfEvenDigits(n) << endl;
    cout << sumOfOddDigits(n) << endl;

    return 0;
}