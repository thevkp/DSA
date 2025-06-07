#include <iostream>
using namespace std;

int setKthBit(int n, int k){
    n = n | (1 << k);

    return n;
}

int main(){
    system("cls");

    int n, k;
    cin >> n >> k;

    cout << setKthBit(n, k) << endl;



    return 0;
}