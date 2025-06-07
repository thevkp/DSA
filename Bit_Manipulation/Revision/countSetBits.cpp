#include <iostream>
#include <bitset>
using namespace std;

int countSetBitsManual(int n){
    int count = 0;

    while(n){
        if(n & 1) ++count;
        n >>= 1;
    }
    return count;
}

int countSetBitsBKT(int n){
    int count = 0;

    while(n){
        n = n & (n - 1);
        count++;
    }

    return count;
}

int bitsetMethod(int n){
    return bitset<32>(n).count();
}

int builtInPopcount(int n){
    return __builtin_popcount(n);
}


int main(){
    system("cls");

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cout << "Manual: " << countSetBitsManual(n) << endl;
        cout << "BKT: " << countSetBitsBKT(n) << endl;
        cout << "bitset: " << bitsetMethod(n) << endl;
        cout << "builtinPopCount: " << builtInPopcount(n) << endl;
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
