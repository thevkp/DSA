// Bit-Bulb Party
// You have n bulbs in a row, initially OFF. Each set bit in the binary representation of a number n represents a switch to flip a bulb ON.
// How many bulbs are ON after performing the operations?



#include <iostream>
using namespace std;

int main(){
    system("cls");

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cout << __builtin_popcount(n) << endl;
    }









    return 0;
}