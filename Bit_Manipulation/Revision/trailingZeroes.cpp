#include <iostream>
using namespace std;

int trailingZeroesManual(int n){
    int count = 0;

    while(n){
        if(n & 1)
            break;
        count++;
        n >>= 1;
    }

    return count;
}

int builtinCTZ(int n){
    return n > 0 ? __builtin_ctz(n) : 0;
}



int main(){
    system("cls");


    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cout << trailingZeroesManual(n) << endl;
        cout << builtinCTZ(n) << endl;
    }



    return 0;
}