#include <iostream>
using namespace std;

int floor(int* arr, int n, int key){
    int start = 0;
    int end = n - 1;

    int floor = -1;
    while(start <= end){
        int mid = start + ( end -start)/ 2;

        if(arr[mid] <= key){
            floor = arr[mid];
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    return floor;
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

    cout << floor(arr, size, target) << endl;

    delete[] arr;

    return 0;
}