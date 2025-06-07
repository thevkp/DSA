#include <iostream>
using namespace std;

template<typename T>

T maxi(T a, T b){
    return (a > b) ? a : b;
}


int main(){
    system("cls");

    cout << maxi('a', 'A') << endl;

    return 0;
}