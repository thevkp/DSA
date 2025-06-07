#include <iostream>
#include <bitset>
using namespace std;

string stringToBin(string& str){
    string output = "";

    for(char c : str){
        output += bitset<8>(c).to_string() + " ";
    }

    return output;
}


int main(){ 
    system("cls");

    string input;
    getline(cin, input);


    cout << stringToBin(input) << endl;



    return 0;
}