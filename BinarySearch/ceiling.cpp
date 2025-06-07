#include <iostream>
using namespace std;

int findCeiling(int* arr, int n, int key){
    int start = 0;
    int end = n - 1;
    int ceil = -1;

    while(start <= end){
        int mid = start + (end - start) / 2;

        if(key <= arr[mid]){
            ceil = arr[mid];
            end = mid - 1;
        }
        else
            start = mid + 1;
    }

    return ceil;
}

int floor(int* arr, int n, int key){
    int start = 0;
    int end = n - 1;
    int floor = -1;

    while(start <= end){
        int mid = start + (end - start) / 2;

        if(key >= arr[mid]){
            floor = arr[mid];
            start = mid + 1;
        }
        else   
            end =  mid - 1;
    }

    return floor;
}

int main(){
    int size, key;
    cin >> size >> key;
    int* arr = new int[size];

    int input;
    for(int i = 0; i < size; i++){
        cin >> input;
        arr[i] = input;
    }

    cout << "Ceil: " << findCeiling(arr, size, key) << "\n";
    cout << "Floor: " << floor(arr, size, key) << "\n";

    delete[] arr;

    return 0;
}