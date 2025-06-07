#include <iostream>
using namespace std;

void print(int n){
    if(n == 0){
        return;
    }

    print(n - 1);
    cout << n << " ";
}

void Nto1(int n){
    if(n == 0){
        return;
    }

    cout << n << " ";
    print(n - 1);
}

int main(){
    system("cls");

    int n;
    cin >> n;

    print(n);
    cout << endl;
    Nto1(n);

    return 0;
}