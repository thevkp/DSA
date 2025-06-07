#include <iostream>
using namespace std;


void reverse(int* arr, int start, int end){
    if(start >= end)
        return;

    swap(arr[start], arr[end]);
    reverse(arr, start + 1, end - 1);
}

void printArr(int* arr, int start, int size){
    if(start == size)
        return;
    cout << arr[start] << " ";
    printArr(arr, start + 1, size);
}

int main(){
    system("cls");

    int size;
    cin >> size;

    int* arr = new int[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    reverse(arr, 0, size - 1);
    printArr(arr, 0, size);


    delete[] arr;

    return 0;
}