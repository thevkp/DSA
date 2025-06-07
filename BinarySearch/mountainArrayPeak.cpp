#include <iostream>
using namespace std;

int findPeak(int* arr, int n){
    int start = 0;
    int end = n - 1;

    // int peak = arr[0];
    while(start < end){
        int mid = start + (end - start) / 2;
        // peak = arr[mid];
        if(arr[mid] > arr[mid + 1]){
            end = mid;
        }
        else if(arr[mid] < arr[mid + 1])
            start = mid + 1;
        // else
        //     return arr[mid];
    }

    return arr[start];
}

// void printArray(int* arr, int n){
//     for(int i = 0; i < n; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

int main(){
    system("cls");

    int size;
    cin >> size;

    int* arr = new int[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    
    cout << findPeak(arr, size) << endl;


    delete[] arr;

    return 0;
}