#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

// 1st method
bool isPalindrome(string str){
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    string temp = str;
    reverse(str.begin(), str.end());

    return temp == str;
}

// 2nd method
bool isPalindrome1(string& str){
    // transform(str.begin(), str.end(), str.begin(), ::tolower);

    int start = 0;
    int end = str.length() - 1;
    while(start < end){
        if(tolower(str[start++]) - 32 != tolower(str[end--]) - 32)
            return false;
    }

    return true;
}

//3rd method
bool isPalindrome2(string str){
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    string temp = str;
    reverse(temp.begin(), temp.end());

    return temp.compare(str);
}

//4th method
bool isPalindrome3(string str){
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    string temp = "";
    
    int n = str.length() - 1;
    for(int i = n; i >= 0; i--){
        temp = temp + str[i];
    }

    return temp == str;
}

//5th method
bool isPalindrome4(string str){
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    string temp = str;
    reverse(temp.begin(), temp.end());

    int start = 0;
    int end = str.length() - 1;

    while(start <= end){
        if(str.find(str[start]) != temp.find(temp[start])){
            return false;
        }

        start++;
    }

    return true;
}

//6th method
bool isPalindrome5(string str){ 
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    // cout << str << endl;
    string temp = str;
    reverse(temp.begin(), temp.end());

    // cout << temp << endl;

    int n = str.length();
    for(int i = 0; i < n; i++){
        if(str.substr(i, 1) != temp.substr(i, 1))
            return false;
        
        // cout << str.substr(i, 1) << " " << temp.substr(i, 1) << endl;
    }

    return true;
}

//7th method
bool isPalindrome6(string str){
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    string temp = str;
    reverse(str.begin(), str.end());

    int start = 0;
    int end = str.length() - 1;
    while(start < end){
        if(str.at(start) != temp.at(start))
            return false;
        
        start++;
    }

    return true;
}

//8th method
// bool isPalindrome7(string str){
//     transform(str.begin(), str.end(), str.end(), ::tolower);

//     string temp = str;
//     reverse(temp.begin(), temp.end());

//     char ch = temp[0] - 'a';
//     temp.replace(1, 1, ::string(1, ch));

//     return  temp == str ? false : true;
// }

bool checkPalindrome(string& str){
    size_t start = 0;
    size_t end = str.length() - 1;

    while(start < end){
        if(tolower(str[start]) != tolower(str[end]))
            return false;
        start++;
        end--;
    }

    return true;
}

int main(){ 
    string str;
    // cin >> str;
    getline(cin, str);
    cout << str << endl;


    cout << boolalpha;
    cout << "Method 0: " << isPalindrome(str) << endl;
    cout << "Method 1: " << isPalindrome1(str) << endl;

    if(!isPalindrome2(str)){
        cout << "Method 2: " << "true" << endl;
    }
    else
        cout << "Method 2: " << "false" << endl;

    cout << "Method 3: " << isPalindrome3(str) << endl;
    cout << "Method 4: " << isPalindrome4(str) << endl;
    cout << "Method 5: " << isPalindrome5(str) << endl;
    cout << "Method 6: " << isPalindrome6(str) << endl;
    // cout << isPalindrome7(str) << endl;
    cout << "Method 8: " << checkPalindrome(str) << endl;


    return 0;
}