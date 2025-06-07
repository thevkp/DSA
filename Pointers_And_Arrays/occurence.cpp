#include <iostream>
using namespace std;

int occurence(char str[], int ch, int size){
    int count = 0;
    while(*str){
        if(*str == ch)
            count++;
        str++;
    }
    return count++;
}

int main(){
    system("cls");
    char char_arr[15] = "minimum";
    int maxLength = sizeof(char_arr)/sizeof(char_arr[0]);

    // char input;
    // cin >> input;
    // for(int i = 0; i < maxLength && input; i++){
    //     char_arr[i] = input;
    //     cin >> input;
    // }

    // char key;
    // cin >> key;

    cout << occurence(char_arr, 'm', maxLength) << endl;

    return 0;
}