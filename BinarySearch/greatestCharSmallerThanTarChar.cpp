#include <iostream>
using namespace std;

char exFloor(char* arr, int size, int key){
    int start = 0;
    int end = size - 1;

    char exclusiveFloor = ' ';
    while(start <= end){
        int mid = start + (end - start) / 2;

        if(arr[mid] < key){
            exclusiveFloor = arr[mid];
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    return exclusiveFloor;
}

int main(){
    int size;
    cin >> size;

    char* arr = new char[size];
    
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    char target;
    cin >> target;

    cout << exFloor(arr, size, target) << endl;



    delete[] arr;
    return 0;
}