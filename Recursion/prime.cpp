#include <iostream>
#include <cmath>
using namespace std;

bool prime(int n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }

    return true;
}


int main(){
    system("cls");
    
    int n;
    cin >> n;

    cout << boolalpha;
    cout << prime(n) << endl;

    return 0;
}