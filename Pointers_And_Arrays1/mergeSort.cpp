#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left[n1];
    int right[n2];

    for(int i = 0; i < n1; i++){
        left[i] = arr[low + i];
    }
    for(int j = 0; j < n2; j++){
        right[j] = arr[mid + j + 1];
    }

    int i = 0, j = 0;
    int k = low;

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


void mergeSort(int arr[], int low, int high){
    if(low >= high){
        return;
    }
    int mid =  low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] <<  " ";
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

    cout << "Original Array: " << endl;
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);

    cout << "Sorted Array: " << endl;
    printArray(arr, n);


    delete[] arr;
    return 0;
}