#include <iostream>
#include <typeinfo>
using namespace std;


int main(){
    int a = 10;
    cout << typeid(a).name() << endl;
    cout << typeid((int *)a).name() << endl;
    int* address = &a;
    cout << typeid(address).name() << endl;

    return 0;
}