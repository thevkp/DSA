#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


void reverseWords(string& str){
    int n = str.length();
    int i = 0;
    int l = 0, r = 0;
    while(i < n){
        while(i < n && str[i] != ' '){
            r++;
            i++;
        }
        if(l < r){
            reverse(str.begin() + l, str.begin() + r);
            
            str[i] = ' ';
            r++;
            l = r;
        }
        i++;
    }
}

int main(){
    system("cls");

    string str;

    getline(cin, str);

    reverseWords(str);
    cout << str << endl;


    return 0;
}