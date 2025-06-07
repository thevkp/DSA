#include <iostream>
using namespace std;

int rationalNums(int n){
    if(n == 0){
        cout << 1 << endl;
    
    }
    
    rationalNums(n - 1) + (1 / rationalNums(n - 1));
}




int main(){
    int n;
    cin >> n;

    rationalNums(n);


    return 0;
}