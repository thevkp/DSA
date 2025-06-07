#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target){
    int start = 0;
    int end = n - 1;

    if(arr[end] < target)
        return end + 1;
    if(arr[start] > target)
        return start;

    int mid = start + (end - start) / 2;
    while(start <= end){
        if(arr[mid] == target)  
            return mid;
        else if(arr[mid] < target){
            start = mid + 1;
            // cout << start << endl;
        }
        else    
            end = mid - 1;
            
        mid = start + (end - start) / 2;
    }
    return mid;
}


int main(){ 
    system("cls");
    int size;
    cin >> size;

    int* arr = new int[size];

    int input;
    for(int i = 0; i < size; i++){
        cin >> input;
        arr[i] = input;
    }

    int value;
    cin >> value;
    cout << binarySearch(arr, size, value) << endl;

    return 0;
}