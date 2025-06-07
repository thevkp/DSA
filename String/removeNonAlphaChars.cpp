#include <iostream>
#include <string>
using namespace std;


// ignore non-alphabet characters and store alphabetical characters in a temporary string named ans
string removeNonAlpha(string& s){
    int n = s.length();

    string ans = "";
    for(int i = 0; i < n; i++){ 
        if(isalpha(s[i])){
            ans += toupper(s[i]);
        }
    }

    return ans;
}


int main(){
    system("cls");

    string str;
    cin >> str;


    string strAlpha = removeNonAlpha(str);
    cout << strAlpha << endl;




    return 0;
}
