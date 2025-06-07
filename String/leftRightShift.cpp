#include <iostream>
using namespace std;

int main(){
    system("cls");

    int n;
    cin >> n;

    bool ans = (n & 1) ? false : true;
    cout << boolalpha;
    cout << ans << endl;


    return 0;
}