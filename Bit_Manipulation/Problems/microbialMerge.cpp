// You have n microbes.
// Every second, if the number of microbes is even, they merge into pairs (cut in half).
// If the number is odd, you add one more microbe manually before merging.

// Your goal:
// How many microbes did you manually add to reduce all of them down to 1?





#include <iostream>
using namespace std;

int mergeTo1(int n){

    return __builtin_popcount(n) - 1;
}


int main(){
    system("cls");

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cout << mergeTo1(n) << endl;
    }



    return 0;
}