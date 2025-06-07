#include <iostream>
#include <string>
using namespace std;

void rev(string str, int n, string& revStr) {
    if(n == 0) return;

    revStr = revStr + str[n - 1];
    rev(str, n - 1, revStr);
}



int main(){
    system("cls"); 

    string str, ans = "";
    cin >> str;

    int n = str.length();

    rev(str, n, ans);

    cout << ans << endl;

    return 0;
}