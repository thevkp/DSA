#include <iostream>
#include <vector>
using namespace std;

int fact(int n){
    if(n == 0 || n == 1){
        return 1;
    }

    return n * fact(n - 1);
}



int main(){
    system("cls");

    int n;
    cin >> n;

    cout << fact(n) << endl;

    return 0;
}

// 0 1 1 2 3 5 8 13 21