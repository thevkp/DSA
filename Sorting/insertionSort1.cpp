#include <iostream>
using namespace std;

void insertionSort(int* arr, int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

}

void printArr(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main(){
    int size;
    cin >> size;

    int* arr = new int[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    insertionSort(arr, size);
    printArr(arr, size);


    delete[] arr;

    return 0;
}