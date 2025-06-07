#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
#include <stack>
using namespace std;

// remove all the consecutive duplicates
void removeConsecutive(string& str) {
    int n = str.length();
    for(int i = 0; i < n - 2; i++){
        if(str[i] == str[i + 1] && str[i + 1] == str[i + 2]){
            str.erase(i, 3);
            i = i - 1;
            n = str.length();
        }
    }
}

// leetcode stolen solution
string removeDuplicates(string s) {
    int i = 0, n = s.length();
    for (int j = 0; j < n; ++j, ++i) {
        s[i] = s[j];
        if (i > 0 && s[i - 1] == s[i]) // count = 2
            i -= 2;
    }
    cout << i << endl;
    return s.substr(0, i);
}


// void removeDuplicates(string& str, string& ans){
//     int n = str.length();
//     for(int i = 0; i < n; i++){
//         if(str[i] != str[i + 1]){
//             ans = ans + str[i];
//         }
//     }
// }

// using unordered set(creatig a strng containing only unique characters)

// void removeDuplicates1(string& str, string& ans){
//     unordered_set<char> s;
//     ans = "";
//     for(char c : str){
//         if(s.find(c) == s.end()){
//             ans += c;
//             s.insert(c);
//         }
//     }
// }


int main(){
    system("cls");

    string input, ans = "";
    cin >> input;

    // removeDuplicates(input, ans);
    // cout << ans << endl;
    // removeDuplicates1(input, ans);
    // cout << ans << endl;


    removeConsecutive(input);
    cout << input << endl;
    string res = removeDuplicates(input);
    cout << res << endl;
    return 0;
}