#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


void reverseK(string& str, int k){
    int n = str.length();

    for(int i = 0; i < n; i += 2 * k){
        if(i + k <= n){
            reverse(str.begin() + i, str.begin() + i + k);
        }
        else{
            reverse(str.begin() + i, str.end());
        }
    }
}



int main(){
    system("cls");

    string str;

    cin >> str;

    int k;
    cin >> k;

    reverseK(str, k);

    cout << str << endl;



    return 0;
}