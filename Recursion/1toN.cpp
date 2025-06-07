#include <iostream>
using namespace std;

void Nto1(int n, int s){
    if(s == n){
        return;
    }

    Nto1(n, s + 1);
    cout << s + 1 << " ";
}

void print(int n){  
    Nto1(n, 0);
}

void _1ToN(int n){
    if(n == 0){
        return;
    }

    _1ToN(n - 1);
    cout << n << " ";
}


int main(){
    system("cls");

    int n;
    cin >> n;

    print(n);
    cout << endl;
    _1ToN(n);
    return 0;
}