#include <iostream>
using namespace std;


void merge(int* arr, int start, int mid, int end){
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

    int i = 0, j = 0;
    int k = start;

    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int* arr, int start, int end){
    if(start >= end){
        return;
    }

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void printArray(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    system("cls");
    
    int n;
    cin >> n;

    int* arr = new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);
    printArray(arr, n);

    

    return 0;
}