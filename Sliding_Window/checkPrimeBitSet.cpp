#include <iostream>
#include <bitset>
using namespace std;

const int MAX = 1e6 + 1;
bitset<MAX> isPrime;


void sieve(){
    isPrime.set();

    isPrime[0] = isPrime[1] = 0;

    for(int i = 2; i * i <= MAX; i++){
        if(isPrime[i]){
            for(int j = i * i;  j <= MAX; j += i){
                isPrime[j] = 0;
            }
        }
    }
}

bool checkPrime(int n){
    return isPrime[n];
}



int main(){
    system("cls");

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cout << boolalpha;
        cout << checkPrime(n) << endl;
    }

    isPrime.set();
    cout << isPrime.count() << endl;
    isPrime.flip();
    cout << isPrime.count() << endl;
    cout << boolalpha;
    isPrime[55] = true;
    isPrime[54] = true;
    cout << isPrime.any() << endl;
    cout << isPrime.none() << endl;
    cout << isPrime.test(45) << endl;
    cout << isPrime.test(54) << endl;

    return 0;
}