#include <iostream>
using namespace std;

int sum(int n){
    if(n % 2 != 0)
        n = n - 1;
        
    if(n == 0){
        return 0;
    }

    return n + sum(n - 2);
}

int main(){
    system("cls");

    int n;
    cin >> n;

    cout << sum(n) << endl;

    return 0;
}