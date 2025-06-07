#include <iostream>
using namespace std;


int setKthBit(int n, int k){
    if(n < 0)
        return n;
    
    if(k < 0)
        return n;
    
    return n | (1 << k); // 0-based indexing
}



int main(){
    system("cls");

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        cout << setKthBit(n, k) << endl;
    }


    return 0;
}