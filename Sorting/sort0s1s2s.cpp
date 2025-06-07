#include <iostream>
using namespace std;

void sort01(int* arr, int n){
    int i = 0;
    for(int j = 0; j < n; j++){
        if(arr[j] == 0)
            swap(arr[i++], arr[j]);
    }
}

void printArr(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    system("cls");

    int size;
    cin >> size;

    int* arr = new int[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    sort01(arr, size);
    printArr(arr, size);

    delete[] arr;

    return 0;
}