#include <iostream>
using std::cout;
using std::endl;


int main(){
    system("cls");
    int *ptr = nullptr;
    int num = 10;
    ptr = &num;

    cout << *ptr << endl;

    return 0;
}