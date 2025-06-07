#include <iostream>
using namespace std;


void printArr(int*, int , int);

void mergeSort(int* arr, int start, int end){
    if(start >= end)
        return;
    int mid = start + (end - start) / 2;


    printArr(arr, start, mid);
    mergeSort(arr, start, mid);
    // printArr(arr, mid + 1, end);
    // mergeSort(arr, mid + 1, end);
}

void printArr(int* arr, int start, int end){
    while(start <= end){
        cout << arr[start++] << " ";
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

    mergeSort(arr, 0, size - 1);


    delete[] arr;
    return 0;
}