#include <iostream>
using namespace std;

int fib(int n){
    if(n == 0 || n == 1)
        return n;
    
    return fib(n -1) + fib(n - 2);
}

int main(){
    system("cls");
    int N;
    cin >> N;

    while(N != -1){
        cout << fib(N) << endl;
        cin >> N;
    }
    
    return 0;
}