#include <iostream>
#include <string>
using namespace std;


string decToBin(int n){
    string ans = "";

    while(n){
        char rem = n % 2;
        cout << rem << endl;
        ans.push_back(rem);
        cout << ans;
        n >>= 1;
    }

    return ans;
}



int main(){
    system("cls");

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cout << decToBin(n) << endl;
    }

    // cout << to_string(2) << endl;
    string ans = "";
    ans.push_back('a');
    ans.push_back('b');
    ans.push_back(4 % 5);
    cout << ans << endl;
    return 0;
}