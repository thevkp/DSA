#include <iostream>
using namespace std;


bool checkPrime(int n){
    if(n < 2)
        return false;

    for(int i = 2; i < n; i++){
        if(n % i == 0)
            return false;
    }

    return true;
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