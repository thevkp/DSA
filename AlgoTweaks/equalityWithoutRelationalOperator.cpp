#include <iostream>
using namespace std;

int main(){

    int a, b;
    cin >> a >> b;

    cout << boolalpha;
    cout << !(a ^ b) << endl;


    return 0;
}