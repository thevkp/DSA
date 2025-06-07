//  Virus Split
// A virus can replicate into two when it has even cells.
// If it has odd cells, it can self-destruct one to become even.

// Given a number of virus cells n, find the minimum number of steps to make all cells disappear.



// 2. Counting Magical Bits
// Given an integer n, count how many times you need to:

// Find the lowest set bit using n & -n

// Subtract it from n

// until n becomes 0.


#include <iostream>
#include <cmath>
using namespace std;


int destroyTheVirus(int n){
    int steps = 0;

    while(n){
        steps += (n & 1);
        n >>= 1;
        steps++;
    }

    return steps - 1;
}



int main(){
    system("cls");

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        if(n <= 0){
            cout << "Enter valid number of cells.";
            t++;
            continue;
        }

        cout << destroyTheVirus(n) << endl;
        cout << __builtin_popcount(n) + floor(log2(n)) << endl;
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