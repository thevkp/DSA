#include <iostream>
#include <string>
using namespace std;

string binToInt(string& str){
    int res = 0;
    string ans = "";
    for(char& bit : str){
        if(bit != ' '){ 
            res = res * 2 + (bit - '0');
        }
        else{
            ans += string(1, static_cast<char>(res)) ;
            res = 0;
        } 
    }
    ans += string(1, static_cast<char>(res));

    return ans;
}

int main(){
    system("cls");

    string str;
    getline(cin, str);


    cout << binToInt(str) << endl;



    return 0;
}