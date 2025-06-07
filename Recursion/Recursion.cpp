#include <iostream>
using namespace std;

int sum(int N){
    if(N == 0)
        return 0;

    return (N % 10) + sum(N / 10);
}


int main(){
    system("cls");
    int digit;
    cin >> digit;

    cout << sum(digit) << endl;

    return 0;
}