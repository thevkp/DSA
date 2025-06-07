#include <iostream>
using namespace std;


bool isPowerOfTwo(int n){
    return n > 0 ? (n & (n - 1)) == 0 : 0;
}




int main(){
    system("cls");

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cout << boolalpha;
        cout << isPowerOfTwo(n) << endl;
    }



    return 0;
}