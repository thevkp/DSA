#include <iostream>
using namespace std;

void printArr(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int* arr, int n){
    for(int i = 1; i < n; i++){
        int curr = arr[i];
        int j = i - 1;
        while(arr[j] > curr && j >= 0){
            arr[j + 1] = arr[j];
            j--;
        }
        printArr(arr, n);
        arr[j + 1] = curr;
    }
}

int main(){
    system("cls");
    int size;
    cin >> size;

    int* arr = new int[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    insertionSort(arr, size);
    
    cout << "Sorted array: ";
    printArr(arr, size);

    delete[] arr;

    return 0;
}