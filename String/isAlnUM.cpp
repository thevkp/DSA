#include <iostream>
#include <string>
using namespace std;

bool checkValid(char ch){
    return isalnum(ch) != 0;
}

int main(){
    system("cls");
    // char ch;
    // cin >> ch;

    // cout << boolalpha;
    // cout << isalnum(ch) << endl;

    string str;
    getline(cin, str);

    // int left = 0;
    // int right = str.length() - 1;
    // while(left < right){
    //     while(left < right && checkValid(str[left]) == 0){
    //         left++;
    //     }
    //     while(left < right && checkValid(str[right]) == 0){
    //         right--;
    //     }
    // }

    for(int i = 0; i < str.length(); i++){
        if(checkValid(str[i]) == 0){
            if(str[i] == ' ')
            {
                cout << "space" << endl;
            }
            else 
                cout << str[i] << endl;
        }
    }
    // cout << str << endl;

    return 0;
}