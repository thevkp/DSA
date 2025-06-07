#include <iostream>
using namespace std;


void merge(int* arr, int start, int mid, int end){
    cout << "Start: " << start << " mid: " << mid << " end: " << end << endl;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int left[n1];
    int right[n2];

    for(int i = 0; i < n1; i++){
        left[i] = arr[start + i];
    }

    for(int j = 0; j < n2; j++){
        right[j] = arr[mid + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = start;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            arr[k] = left[i++];
        }
        else
            arr[k] = right[j++];
        k++;
    }

    while(i < n1){
        arr[k++] = left[i++];
    }

    while(j < n2){
        arr[k++] = right[j++];
    }
}


void sort(int* arr, int start, int end){
    if(start >= end)
        return;
    
    int mid = start + (end - start) / 2;
    sort(arr, start, mid);
    sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
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

    sort(arr, 0, size - 1);
    printArr(arr, size);


    delete[] arr;
    return 0;
}