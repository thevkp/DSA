#include <iostream>
using namespace std;

// void printArr(int arr[][3]){
//     for(int i = 0; i < )
// }


int main(){
    int arr[2][3] = {{1,2}, {3,4,5}}; // by default arr[0][2] = 0, also called row major allocation
    int brr[2][3] = {1,2,3,4,5};      // last position(arr[1][2] = 0) will be initialized to 0
    int crr[2][3]; // will be initialized to garbage value
    int drr[2][3] = {0}; // every element will be zero
    int err[2][3] = {1}; // err[0][0] = 1, else will be 0
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            cout << brr[i][j] << " ";
        }
    }
    cout << endl;


    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            cout << crr[i][j] << " ";
        }
    }
    cout << endl;


    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            cout << drr[i][j] << " ";
        }
    }
    cout << endl;


    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            cout << err[i][j] << " ";
        }
    }
    cout << endl;

    return 0;
}