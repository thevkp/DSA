#include <iostream>
using namespace std;

int binarySearchRevSorted(int* arr, int start, int end, int key){
    while(start <= end){
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

int binarySearchOrderAgnostic(int* arr, int n, int key){
    int start = 0;
    int end = n - 1;
    bool isAgnostic = arr[start] > arr[end];

    if(isAgnostic)
        return binarySearchRevSorted(arr, start, end, key);
    else{
        while(start <= end){
            int mid = start + (end - start) / 2;

            if(arr[mid] == key)
                return mid;
            else if(arr[mid] < key)
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1;
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

    cout << binarySearchOrderAgnostic(arr, size, target) << endl;



    delete[] arr;
    return 0;
}