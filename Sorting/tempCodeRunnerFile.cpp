#include <iostream>
using namespace std;

void insertionSort(int* arr, int n){
    for(int i = 1; i < n; i++){
        int curr = arr[i];
        int j = i - 1;
        while(arr[j] > curr && j >= 0){
            arr[j + 1] = arr[j];
            j--;
        }
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
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}