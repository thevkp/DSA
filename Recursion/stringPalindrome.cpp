#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool equality(string& str, int start, int end){   
    // Base case, if start and end meets, string is a palindrome
    if(start >= end)
        return true;
    
    if(tolower(str[start]) != tolower(str[end]))
        return false;

    return equality(str, start + 1, end - 1);
}


bool isPalindrome(string& str){
    if(str.empty())
        return true;
    
    return equality(str, 0, str.size() - 1);
}


int main(){ 
    system("cls");
    string str;
    getline(cin, str);

    cout << boolalpha;
    cout << isPalindrome(str) << endl;


    return 0;
}