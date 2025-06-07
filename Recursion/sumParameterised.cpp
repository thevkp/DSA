#include <iostream>
using namespace std;

void sum(int n, int& s){
    if(n == 0){
        return;
    }
    s = s + n;
    sum(n-1, s);
}

int main(){
    system("cls");

    int n;
    cin >> n;
    int s = 0;
    sum(n, s);
    cout << s << endl;

    return 0;
}