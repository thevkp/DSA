#include <iostream>
using namespace std;

void reverse(int n, int& rev){
    if(n == 0) return;

    int digit = n % 10;
    rev = rev * 10 + digit;
    
    reverse(n / 10, rev);
}

int main(){
    system("cls");
    
    int n;
    cin >> n;

    int rev = 0;
    reverse(n, rev);

    cout << rev << endl;

    return 0;
}