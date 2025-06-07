#include <iostream>
using namespace std;

int firstOccurence(int* arr, int n, int key){
    int start = 0;
    int end = n - 1;
    int firstOccurence = -1;

    while(start <= end){
        int mid = start + (end - start) / 2;

        if(arr[mid] == key){
            firstOccurence = mid;
            end = mid - 1;
        }
        else if(arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return firstOccurence;
}

int lastOccurence(int* arr, int size, int key){
    int start = 0;
    int end = size - 1;

    int lastOccurence = -1;
    while(start <= end){
        int mid = start + (end - start) / 2;

        if(arr[mid] == key){
            lastOccurence = mid;
            start = mid + 1;
        }
        else if(arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return lastOccurence;
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

    cout << "First Occurence: " << firstOccurence(arr, size, target) << endl;
    cout << "Second Occurence: " << lastOccurence(arr, size, target) << endl;



    return 0;
}