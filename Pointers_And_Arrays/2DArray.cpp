#include <iostream>
#include <typeinfo>
using namespace std;

int main(){
    system("cls");
    int data[3][4] = {{1,2,3,4}, {9,8,7,6}, {2,4,6,8}};
    cout << typeid(data).name() << endl;

    cout << ((data[0][0])) << endl;
    cout << typeid(data[0][0]).name() << endl;
    cout << typeid(data).name() << endl;
    cout << typeid(data[0]).name() << endl;
    cout << typeid(*(data[0])).name() << endl;
    cout << *data[0] << endl;
    cout << data[0][0] << endl;
    return 0;
}