#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

char dominantChar(string& str){
    unordered_map<char, int> freq;

    for(char& ch : str){
        freq[ch]++;
    }

    int maxFreq = 0;
    char domChar;
    for(auto& it : freq){
        if(maxFreq < it.second){
            maxFreq = it.second;
            
        }
    }

    return freq[]
}


int main(){
    string str;
    getline(cin, str);

    cout << dominantChar(str) << endl;


    return 0;
}