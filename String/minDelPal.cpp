#include <iostream>
#include <string>
using namespace std;


int minDels(string& str){
    int i = 0;
    int j = str.length() - 1;
    int dels = 0;
    while(i < j){
        if(str[i] != str[j]){
            dels++;
        }
        i++;
        j--;
    }

    // return str.length() - dels;
    return dels;
}


int main(){
    system("cls");

    string str;

    cin >> str;


    cout << minDels(str) << endl;



    return 0;
}