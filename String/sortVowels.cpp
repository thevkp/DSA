#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isVowel(char ch){
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void sortVowels(string& str){
    vector<char> vowels;

    for(char& ch : str){
        if(isVowel(ch))
            vowels.push_back(ch);
    }

    sort(vowels.begin(), vowels.end());

    int vowelIndex = 0;
    for(char& ch : str){
        if(isVowel(ch))
            ch = vowels[vowelIndex++];
    }
}

int main(){
    string str;
    getline(cin, str);

    sortVowels(str);
    cout << str << endl;


    return 0;
}