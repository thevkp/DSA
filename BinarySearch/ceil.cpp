#include <iostream>
using namespace std;


int ceiling(int* arr, int size, int key){
    int start = 0;
    int end = size - 1;

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


int main(){
    int size;
    cin >> size;

    int* arr = new int[size];

    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    int target;
    cin >> target;
    cout << ceiling(arr, size, target) << endl;

    delete[] arr;


    return 0;
}