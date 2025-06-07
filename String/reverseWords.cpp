#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// using stringstream
string rev(string s){
    stringstream ss(s);

    string token = "";
    string result = "";

    while(ss >> token){
        result = token + " " + result;
    }

    return result.substr(0, result.length() - 1);
}

int main(){
    system("cls");

    string input;
    getline(cin, input);

    cout << input << endl;

    cout << rev(input) << "-1" << endl;

    return 0;
}