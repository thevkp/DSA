#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

// const int MAX = 1e6 + 1;
// vector<bool> isPrime(MAX, 1);


int countSetBitsManual(int n){
    int count = 0;

    while(n){
        if(n & 1)
            count++;
        n >>= 1;
    }

    return count;
}

int bitSet(int n){
    return bitset<32>(n).count();
}

int kernighanTrick(int n){
    int count = 0;

    while(n){
        n = n & (n - 1);
        count++;
    }

    return count;
}

int builtinPopCount(int n){
    return __builtin_popcount(n);
}

int main(){ 
    system("cls");

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;


        cout << countSetBitsManual(n) << endl;
        cout << kernighanTrick(n) << endl;
        cout << bitSet(n) << endl;
        cout << builtinPopCount(n) << endl;
    }


    return 0;
}


// 10
// 0
// 1
// 15
// 42
// 255
// 1024 
// 2147483647 
// 0 
// 123456789 
// 999999999

