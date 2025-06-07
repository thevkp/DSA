#include <iostream>
using namespace std;

void reverse(int* arr, int n){
    int start = 0;
    int end = n - 1;

    while(start < end){
        swap(arr[start++], arr[end--]);
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

    reverse(arr, size);
    printArr(arr, size);
    
    delete[] arr;

    return 0;
}