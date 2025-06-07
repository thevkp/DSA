#include <iostream>
using namespace std;

int lowestSetBitManual(int n){
    int pos = 0;

    while(n){
        if(n & 1){
            pos++;
            break;
        }

        n >>= 1;
        pos++;
    }

    return pos;
}

int builtinCTZ(int n){
    return n > 0 ? __builtin_ctz(n) + 1 : 0;
}

int isolationBKT(int n){
    if(n == 0) return 0;

    int isolatedBit = n & -n; // keeps only the lowest set bit

    int pos = 1;
    while(isolatedBit >>= 1){
        // isolatedBit = isolatedBit & (isolatedBit - 1);
        pos++;
    }

    return pos;
}

int main(){
    system("cls");

    int t;
    cin >> t;


    while(t--){
        int n;
        cin >> n;

        cout << lowestSetBitManual(n) << endl;
        cout << builtinCTZ(n) << endl;
        cout << isolationBKT(n) << endl;
    }


    return 0;
}