#include <iostream>
using namespace std;

int binarySearch(int* arr, int start, int end, int key){
    while(start <= end){
        int mid = start + (end - start) / 2;

        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int findPos(int* arr, int key){
    int low = 0;
    int high = 1;

    while(key > arr[high]){
        int newLow = high + 1;

        high = high + (high - low + 1) * 2;
        low = newLow;
    }

    return binarySearch(arr, low, high, key);
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

    cout << findPos(arr, target) << endl;


    delete[] arr;
    return 0;
}