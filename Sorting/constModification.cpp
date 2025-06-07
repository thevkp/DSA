#include <iostream>
using namespace std;


int main(){
    system("cls");

    const int num = 10;
    int* ptr = (int*)&num;
    *ptr = 20;
    cout << num << endl;

    delete ptr;
    return 0;
}