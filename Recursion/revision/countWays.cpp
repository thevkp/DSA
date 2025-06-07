#include <iostream>
using namespace std;


long long countWays(long long n){
    if(n < 0){
        return 0;
    }

    if(n == 0){
        return 1;
    }

    if(n == 1 || n == 2)
        return n;
    
    return countWays(n - 1) + countWays(n - 2);
}

int main(){

    int t;
    cin >> t;

    while(t--){
        long long stairs;
        cin >> stairs;

        cout << countWays(stairs) << endl;
    }



    return 0;
}