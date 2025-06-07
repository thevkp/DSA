#include <iostream>
using namespace std;


int main(){
    
    int num;
    cin >> num;

    cout << boolalpha;
    cout << !(num & 1) << endl;


    return 0;
}