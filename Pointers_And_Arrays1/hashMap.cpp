#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    system("cls");
    unordered_map<char, int> mp;
    mp['a'];
    mp['b'] = 2;

    cout << mp['a'] << endl;

    mp['a']++;
    cout << mp['a'] << endl;
    return 0;
}