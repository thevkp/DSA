#include <iostream>
using namespace std;

template<typename T>

void swapVals(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

int main(){
    system("cls");

    char a = 'a';
    char b = 'b';
    swapVals(a, b);
    cout << a << " " << b << endl;




    return 0;
}