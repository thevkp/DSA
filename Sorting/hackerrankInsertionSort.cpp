#include <iostream>
#include <vector>
using namespace std;


void insertionSorted(vector<int>& arr, int n){
    for(int i = 0; i < n; i++){
        int curr = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] < curr){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }
}

int main(){
    int size;
    cin >> size;


    vector<int> arr(size);
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    insertionSorted(arr, size);
    for(int& num : arr){
        cout << num << " ";
    }


    return 0;
}