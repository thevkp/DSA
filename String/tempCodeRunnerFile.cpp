#include <iostream>
#include <string>
using namespace std;

string binToInt(string& str){
    int res = 0;
    string ans = "";
    for(char& bit : str){
        res = res * 2 + (bit - '0');
    }
    ans += to_string(res);

    return str;
}

int main(){
    system("cls");

    string str;
    getline(cin, str);


    cout << binToInt(str) << endl;



    return 0;
}