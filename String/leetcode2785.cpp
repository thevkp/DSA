#include <iostream>
#include <string>
using namespace std;

bool isVowel(char ch){
    ch = tolower(ch);
    return  ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void reverseVowels(string& s){
    int start = 0;
    int end = s.length() - 1;
    while(start < end){
        if(!isVowel(s[start])) start++;
        if(!isVowel(s[end])) end--;

        if(isVowel(s[start]) && isVowel(s[end]) && s[start] > s[end])
            swap(s[start++], s[end--]);
        start++;
        end--;
    }
}

int main(){
    system("cls");

    string str;
    cin >> str;

    reverseVowels(str);
    cout << str << endl;


    return 0;
}