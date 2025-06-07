#include <iostream>
using namespace std;

// Euclid's theorem on GCD: m%n == 0, then GCD(m, n) = n, else GCD(m, n) = GCD(n, m % n)
int gcd(int m, int n){
    cout << "Executing GCD(" << m << ", " << n << ")" << endl;

    int result;
    if(m % n == 0)
        result = n;
    else
        result = gcd(n, m%n);
    
    cout << "Exiting from GCD(" << m << ", " << n << ")" << ", Result: " << result << endl;

    return result;
}

int gcd1(int m, int n){
    while(m % n != 0){
        int r = m % n;
        m = n;
        n = r;
    }

    return n;
}

int main(){
    system("cls");

    int m, n;
    cin >> m >> n;

    cout << gcd(m, n) << endl;
    cout << gcd1(m, n) << endl;


    return 0;
}