#include <iostream>
using namespace std;

int result(int x, int n){
    if(n == 0)
        return 1;
    if(n == 1)
        return x;
    
    return x * result(x, --n);
}

int main(){
    int base, exponent;
    cin >> base >> exponent;

    cout << result(base, exponent) << endl;

    return 0;
}