#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void reverseWords(vector<char>& str){
    reverse(str.begin(), str.end());

    int n = str.size();
    int i = 0;
    int l = 0;
    int r = 0;

    while(i < n){
        while(i < n && str[i] != ' '){
            str[r] = str[i];
            i++;
            r++;
        }

        if(l < r){
            reverse(str.begin() + l, str.begin() + r);

            str[r] = ' ';
            r++;
            l = r;
        }
        i++;
    }
}




int main(){
    system("cls");

    vector<char> str;
    string line;
    getline(cin, line);

    for (char c : line) {
        if (c != '0') {
            str.push_back(c);
        } else {
            break;
        }
    }


    reverseWords(str);

    for(char& ch : str){
        cout << ch;
    }
    cout << endl;


    return 0;
}