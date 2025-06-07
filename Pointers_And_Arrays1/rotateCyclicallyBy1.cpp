// just pass k = 1 in rightRotation.cpp 
#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int>& arr, int n){
    int end = arr.size() - 1;
    int last = arr[end];
    while(end > 0){
        arr[end] = arr[end - 1];
        end--;
    }
    arr[0] = last;
}


void printArr(vector<int>& arr){
    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr;
    int input;
    cin >> input;
    while(input != -1){
        arr.push_back(input);
        cin >> input;
    }

    rotate(arr, arr.size());

    printArr(arr);

    return 0;
}