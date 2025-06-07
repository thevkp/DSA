#include <iostream>
using namespace std;

void reverse(int& n){
    int num = 0;
    while(n){
        int rem = n % 10;
        num = num * 10 + rem;
        n /= 10;
    }
    n = num;
}

int main(){
    system("cls");
    int N;
    cin >> N;

    reverse(N);
    cout << N << endl;
    return 0;
}