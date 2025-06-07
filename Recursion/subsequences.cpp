#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(string& str, int index, string output, vector<string>& ans){
    if(index >= str.length()){
        ans.push_back(output);
        return;
    }
        
    // exclude;
    solve(str, index + 1, output, ans);

    // include
    char element = str[index];
    output.push_back(element);
    solve(str, index + 1, output, ans);
}



vector<string> subsequence(string& str){
    int index = 0;
    string output = "";
    vector<string> ans;
    solve(str, index, output, ans);
    return ans;
}

int main(){
    string str;
    cin >> str;

    vector<string> ans = subsequence(str);

    for(const auto& s : ans){
        for(char ch : s){
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}