#include <iostream>
#include <bitset>
using namespace std;


const int MAX = 1e6 + 1;
bitset<MAX> isPrime; // each bit set to false;

int main(){
    system("cls");

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;


        isPrime.set();
        cout << isPrime.count() << endl;
        // isPrime.flip();
        // cout << isPrime.count() << endl;
        // cout << boolalpha;
        // isPrime[55] = true;
        // isPrime[54] = true;
        // cout << isPrime.any() << endl;
        // cout << isPrime.none() << endl;
        // cout << isPrime.test(45) << endl;
        // cout << isPrime.test(54) << endl;
    }



    return 0;
}

