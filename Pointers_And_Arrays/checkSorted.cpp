#include <iostream>
using namespace std;

// bool isSorted(int* arr, int size){
//     for(int i = 0; i < size - 1; i++){
//         if(arr[i] > arr[i + 1])
//             return false;
//     }

//     return true;
// }

bool isSorted(int* arr, int size){
    int start = 0;
    int end = size - 1;
    while(start <= end){
        if(arr[start] > arr[start + 1])
            return false;
        else if(arr[end] < arr[end - 1])
            return false;
        start++;
        end--;
    }

    return true;
}

int main(){

    int size;
    cin >> size;

    int* arr = new int[size];

    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }


    cout << boolalpha;
    cout << isSorted(arr, size) << endl;

    delete[] arr;


    return 0;
}