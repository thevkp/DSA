#include <iostream>
using namespace std;

// bool isPalindrome(int n){
//     int rev = 0;
//     int temp = n;
//     while(temp){
//         rev = (rev * 10) + (temp % 10);
//         temp /= 10;
//     }

//     return (temp == n);
// }

bool isPalindrome(int n){   
    static int rev = 0;
    static int temp = n;
    if(temp == 0)
        return 0;
    
    return (n == (rev = (rev * 10) + isPalindrome(temp % 10)));
}

int main(){
    system("cls");
    int num;
    cin >> num;

    cout << boolalpha;
    cout << isPalindrome(num) << endl;

    return 0;
}