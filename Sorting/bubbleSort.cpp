#include <iostream>
using namespace std;

void bubbleSort(int* arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
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

    bubbleSort(arr, size);
    printArr(arr, size);

    delete[] arr;
    return 0;
}

// arr[i] = *(arr + 1)