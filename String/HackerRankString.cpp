#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    system("cls");
    string str1, str2;

    cin >> str1  >> str2;

    cout << str1.length() << " " << str2.length() << endl;
    cout << str1 + str2 << endl;

    swap(str1[0], str2[0]);

    cout << str1 << " " << str2 << endl;

    return 0;
}