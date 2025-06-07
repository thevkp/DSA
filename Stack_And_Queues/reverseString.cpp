#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseStr(string& str){
    stack<int> st;

    for(int i = 0; i < str.length(); i++){
        st.push(str[i]);
    }

    string ans = "";
    while(!st.empty()){
        ans.push_back(st.top());

        st.pop();
    }

    return ans;
}

int main(){
    system("cls");
    string inputStr;
    cin >> inputStr;

    // reverseStr(inputStr);
    cout << "Reverse: " << reverseStr(inputStr)  << endl;

    return 0;
}