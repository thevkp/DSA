#include <iostream>
using namespace std;


bool checkPrime(int n){
    if(n < 2) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;

    for(int i = 5; i * i <= n; i += 6){
        if(n % i == 0 || n % (i + 1) == 0)
            return false;
    }

    return false;
}




int main(){
    system("cls");

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cout << boolalpha;
        cout << checkPrime(n) << endl;
    }



    return 0;
}