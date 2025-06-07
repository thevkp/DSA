#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string rev(string s){
    int n = s.length();
    int i = 0;
    int l = 0, r = 0;
    while(i < n){
        while(i < n && s[i] != ' '){
            s[r] = s[i];
            r++;
            i++;
        }

        if(l < r){
            reverse(s.begin() + l, s.begin() + r);

            s[r] = ' ';
            r++;
            l = r;
        }
        i++;
    }

    return s.substr(0, r - 1);
}

int main(){
    system("cls");

    string input;
    getline(cin, input);

    cout << input << endl;

    cout << rev(input) << "-1" << endl;

    return 0;
}