#include <iostream>
using namespace std;

void sumEven(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        int evenNum = 2 * i;
        sum = sum + evenNum;
    }
    cout << sum << endl;
}

int sum(int n){
    if(n == 0){
        return 0;
    }

    // int evenNum = 2 * n;

    return 2 * n + sum(n - 1);
}

int sumOdd(int n){
    if(n == 0){
        return 0;
    }

    return (2 * n - 1) + sumOdd(n - 1);
}

int main(){
    system("cls");

    int n;
    cin >> n;

    cout << sum(n) << endl;
    sumEven(n);
    cout << sumOdd(n) << endl;

    return 0;
}