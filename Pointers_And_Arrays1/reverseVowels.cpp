#include <iostream>
#include <string>
using namespace std;

bool isVowel(char& ch){
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void revVow(string& str){
    int start = 0;
    int end = str.length();

    while(start < end){
        if(isVowel(str[start]) && isVowel(str[end])){
            swap(str[start++], str[end--]);
        }
        else if(!isVowel(str[start]))
            start++;
        else if(!isVowel(str[end]))
            end--;
    }
}

int main(){
    system("cls");

    string input;
    cin >> input;

    revVow(input);
    cout << input << endl;



    return 0;
}