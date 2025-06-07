#include <iostream>
#include <cctype>
using namespace std;

string onlyAlpha(string& str){
    string ans = "";

    for(char& ch : str){
        if(isalpha(ch))
            ans += tolower(ch);
    }

    return ans;
}

bool isPalindrome(string& str){
    int start = 0;
    int end = str.size() - 1;

    while(start < end){
        if(str[start] != str[end])
            return false;
        
        start++;
        end--;
    }

    return true;
}

int main(){
    system("cls");

    string str;
    getline(cin, str);

    string result = onlyAlpha(str);


    cout << result << endl;
    cout << boolalpha;
    cout << isPalindrome(result) << endl;


    return 0;
}