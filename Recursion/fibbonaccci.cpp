#include <iostream>
#include <vector>
using namespace std;

int fib(int n) {
    if(n == 0 || n == 1){
        return n;
    }
    
    return fib(n - 1) + fib(n - 2);
}

int fibb(int n){
    if(n == 0){
        cout << 0 << " ";
        return 0;
    }
    if(n == 1){
        cout << 1 << " ";
        return 1;
    }

    int ans = fibb(n - 1) + fibb(n - 2);
    cout << ans << endl;
    return ans;
}

int main(){
    system("cls");

    int n;
    cin >> n;

    cout << fib(n) << endl;
    fibb(n);

    return 0;
}