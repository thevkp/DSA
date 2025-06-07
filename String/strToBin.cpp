#include <iostream>
#include <bitset>
#include <string>
using namespace std;

string strToBin(string str){
    string binaryString = "";

    for(char ch : str){
        binaryString += bitset<8>(ch).to_string() +  " ";
    }

    return binaryString;
}

int main(){
    system("cls");

    string input;
    getline(cin, input);

    cout << strToBin(input) << endl;


    return 0;
}