#include <iostream>
#include <string>
using namespace std;


// bool isValid(char ch){
//     return isalnum(ch) != 0;
// }

bool isPalindrome(string& str){
    int left = 0;
    int right = str.length() - 1;

    while(left < right){
        while(left < right && isalnum(str[left]) == 0){
            left++;
        }

        while(left < right && isalnum(str[right]) == 0){
            right--;
        }

        if(left < right && tolower(str[left]) != tolower(str[right]))
            return false;
        
        left++;
        right--;
    }

    return true;
}

int main(){
    system("cls");
    string input;
    getline(cin, input);

    cout << boolalpha;
    cout << isPalindrome(input) << endl;

    return 0;
}