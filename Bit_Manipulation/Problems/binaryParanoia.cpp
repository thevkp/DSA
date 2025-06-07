#include <iostream>
#include <cmath>
using namespace std;


int minStepToRedToZero(int n){
    if(n == 0) return 0;

    int steps = 0;
    while(n){
        if(n & 1){
            n = n - 1;
            steps++;
        }
        else{
            n = n >> 1;
            steps++;
        }
    }

    return steps;
}

int steps(int n){
    if(n == 0) return 0;
    int steps = 0;
    while(n){
        steps += (n & 1);
        n >>= 1;
        steps++;
    }

    return steps - 1;
}

int builtinPop(int n){
    return __builtin_popcount(n) + floor(log2(n));
}


int main(){
    system("cls");

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cout << minStepToRedToZero(n) << endl;
        cout << steps(n) << endl;
        cout << builtinPop(n) << endl;
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