#include <iostream>
using namespace std;

int binarySearch(int* arr, int start, int end, int key){
    while(start <= end){
        int mid = start + (end - start) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int binarySearchAgnostic(int* arr, int start, int end, int key){
    while(start < end){
        int mid = start + (end - start) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] > key)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int findIndex(int* arr, int n, int key){
    int start = 0;
    int end = n - 1;

    int ans = -1;
    while(start < end){
        int mid = start + (end - start) / 2;

        if(arr[mid] > arr[mid + 1]){
            end = mid;
        }
        else if(arr[mid] < arr[mid + 1]){
            start = mid + 1;
        }
    }

    // return arr[start];
    if(arr[start] == key)
        return start;
    else if(key < arr[start]){
        return binarySearch(arr, 0, start, key);
    }
    else
        return binarySearchAgnostic(arr, start + 1, n - 1, key);
}


int main(){
    system("cls");

    int size;
    cin >> size;

    int* arr = new int[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    int target;
    cin >> target;

    cout << findIndex(arr, size, target) << endl;


    delete[] arr;
    return 0;
}