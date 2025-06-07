#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
using namespace std;

void removeDuplicates(string& str, string& ans){
    int n = str.length();
    for(int i = 0; i < n; i++){
        if(str[i] != str[i + 1]){
            ans = ans + str[i];
        }
    }
}

// using unordered set(creatig a strng containing only unique characters)

void removeDuplicates1(string& str, string& ans){
    unordered_set<char> s;
    ans = "";
    for(char c : str){
        if(s.find(c) == s.end()){
            ans += c;
            s.insert(c);
        }
    }
}


int main(){
    system("cls");

    string input, ans = "";
    cin >> input;

    removeDuplicates(input, ans);
    cout << ans << endl;
    removeDuplicates1(input, ans);
    cout << ans << endl;

    return 0;
}