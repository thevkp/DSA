#include <iostream>
using namespace std;

bool isSorted(int* arr, int n){
    for(int i = 1; i < n; i++){
        if(arr[i - 1] > arr[i])
            return false;
    }

    return true;
}


int main(){
    system("cls");

    int size;
    cin >> size;
    
    int* arr = new int[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    cout << boolalpha;
    cout << isSorted(arr, size) << endl;


    delete[] arr;
    return 0;
}