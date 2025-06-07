#include <iostream>
using namespace std;

int lowerBound(int* arr, int n, int k){
    int start = 0;
    int end = n - 1;

    int lb = -1;
    while(start <= end){
        int mid = start + (end - start) / 2;

        if(arr[mid] == k){
            lb = mid;
            end = mid - 1;
        }
        else if(arr[mid] < k){
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    return lb;
}

int main(){
    system("cls");

    int size, target;
    cin >> size >> target;

    int* arr = new int[size];

    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    cout << lowerBound(arr, size, target) << endl;

    delete[] arr;

    return 0;
}

// 25 15 
// 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10 10 11 11 12 12 13

