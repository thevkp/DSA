// 2. Counting Magical Bits
// Given an integer n, count how many times you need to:

// Find the lowest set bit using n & -n

// Subtract it from n

// until n becomes 0.


#include <iostream>
using namespace std;


int countLSBRemovals(int n){
    int count = 0;

    while(n){
        n = n & (n - 1);
        count++;
    }

    return count;
}



int main(){
    system("cls");

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        cout << countLSBRemovals(n) << endl;
        cout << __builtin_popcount(n) << endl;
        cout << (n & (n - 1)) << endl;
    }

    return 0;
}


// 10
// 90
// 7
// 88
// 776
// 255
// 156
// 256
// 128
// 32
// 33
// 98