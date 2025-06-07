#include <iostream>
using namespace std;


int main(){

    int a, b;

    cin >> a >> b;

    // using + operator
    a = a + b;
    b = a - b;
    a = a - b;

    cout << a << " " << b << endl;


    // using ^ operator
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << a << " " << b << endl;

    // using + operator in single line
    a = a + b - (b = a);
    cout << a << " " << b << endl;

    // using ^ in single line
    a = a ^ b ^ (b = a);
    cout << a << " " << b << endl;


    return 0;
}