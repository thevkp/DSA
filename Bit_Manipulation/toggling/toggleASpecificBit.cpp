#include <iostream>
using namespace std;

int toggleBit(int n, int k){
    if(n < 0 || k < 0)
        return n;

    return n ^ (1 << k);
}


int main(){
    system("cls");

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        cout << toggleBit(n , k) << endl;
    }



    return 0;
}