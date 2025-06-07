#include <iostream>
using namespace std;

int power(int a, int b){
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }

    return a * power(a, b - 1);
}

void power1(int a, int b, int& ans) {
    if(b == 0){
        return;
    }
    
    ans = a * ans;
    power1(a, b - 1, ans);
}

int main(){
    system("cls");
    int a, b;
    cin >> a >> b;

    cout << power(a, b) << endl;

    int ans = 1;
    power1(a, b, ans);
    cout << ans << endl;

    return 0;
}