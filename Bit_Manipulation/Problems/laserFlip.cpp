//  Laser Flip
// Problem:
// You have an integer n. In one operation, you can pick the lowest set bit and 
// flip all bits to the left of it (inclusive). Find the minimum number of
//  operations required to make n zero.


#include <iostream>
using namespace std;

int minOps(int n){
    
    int ops = 0;
    while(n){
        n = n & -n;
        ops++;
    }

    return ops;
}

int main(){
    system("cls");

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cout << minOps(n) << endl;
    }




    return 0;
}