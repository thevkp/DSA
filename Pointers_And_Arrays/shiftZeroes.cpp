#include <iostream>
using namespace std;


void shiftRight(int nums[], int n){
    int i = 0;
    for(int j = 0; j < n; j++){
        if(nums[j] != 0)
        {
            swap(nums[j] , nums[i]);
            i++;
        }
    }
}

int main(){
    int size;
    cin >> size;

    int* arr = new int[size];

    int input;
    for(int i = 0; i < size; i++){
        cin >> input;
        arr[i] = input;
    }

    shiftRight(arr, size);
    
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}