#include <iostream>
using namespace std;

int binToInt(string& str){
    int res = 0;
    for(char& bit : str){
        res = res * 2 + (bit - '0');
    }

    return res;
}

int main(){
    system("cls");

    string str;
    cin >> str;


    cout << binToInt(str) << endl;



    return 0;
}