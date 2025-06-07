#include <iostream>
using namespace std;

short findIndex(int* arr, int n){
    short start = 0;
    short end = n - 1;
    short lb = -1;
    while(start <= end){
        int mid = start + (end - start) / 2;

        if(arr[mid] == 1){
            lb = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }

    return lb;
   
}

int main(){
    system("cls");

    int size;
    cin >> size;

    int* arr = new int[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    cout << findIndex(arr, size) << endl;


    delete[] arr;

    return 0;
}

// 0 0 0 0 0 
// 0 0 0 0 0 0 1