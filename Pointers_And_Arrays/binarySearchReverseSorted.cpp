#include <iostream>
using namespace std;

int binarySearch(int* arr, int size, int target){
    int start = 0;
    int end = size - 1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        // cout << "Start: " << start << " mid: " << mid << " end: " << end << endl;

        if(target == arr[mid])
            return mid;
        else if(target < arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int bs(int* arr, int& size, int& target){
    short start = 0;
    short end = size - 1;

    while(start <= end){
        short mid = start + (end - mid) / 2;

        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int main(){
    system("cls");

    int size, target;
    cin >> size >> target;

    int* arr = new int[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    cout << binarySearch(arr, size, target) << endl;
    cout << bs(arr, size, target) << endl;


    delete[] arr;

    return 0;
}