#include <iostream>
using namespace std;

int product(int n){
    if(!n)
        return 1;

    return (n % 10) * product(n / 10);
}


int main(){
    int digit;
    cin >> digit;

    cout << product(digit) << endl;

    return 0;
}