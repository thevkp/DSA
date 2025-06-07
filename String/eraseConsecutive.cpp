#include <iostream>
#include <string>
using namespace std;

// O(1) space , O(n) time
void removeConsecutive(string& s){
    for(int i = 0; i < s.length() - 1; i++){
        if(s[i] == s[i + 1]){
            s.erase(i, 1);
            i--;
        }
    }
}

// O(n) space
string removeConsecutive1(string& s){
    string str = "";
    int len = s.length();
    for(int i = 0; i < len; i++){
        if(i == len || s[i] != s[i + 1]){
            str.push_back(s[i]);
        }
    }
    return str;
}


// O(n) space
string removeConsecutive2(string& s){
    if(s.empty()) return "";

    int len = s.length();
    string str;
    str.push_back(s[0]);

    for(int i = 1; i < len; i++){
        if(s[i - 1] != s[i])
            str.push_back(s[i]);
    }
    return str;
}


int main(){
    system("cls");
    string str;
    cin >> str;

    // removeConsecutive(str);
    // cout << str << endl;
    // cout << removeConsecutive1(str) << endl;
    cout << removeConsecutive2(str) << endl;

    return 0;
}