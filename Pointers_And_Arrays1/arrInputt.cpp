#include <iostream>
using namespace std;


int main(){
    system("cls");
    int i = 0;
    int arr[5] = {1, 2, 3, 4, 5};

    while(i < 10){
        cout << arr[i % 5] << " ";
        i++;
    }

    return 0;
}