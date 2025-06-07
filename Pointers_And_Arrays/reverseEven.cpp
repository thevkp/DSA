#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int>& arr){
    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;
}

void reverseEven(vector<int>& arr, int n){
    int start = 0;
    int end = n - 1;

    while(start < end){
        swap(arr[start], arr[end]);
        start += 2;
        end -= 2;
    }
}

int main(){
    vector<int> arr;
    int input;
    cin >> input;

    while(input != -1){
        arr.push_back(input);
        cin >> input;
    }

    reverseEven(arr, arr.size());
    printArr(arr);



    return 0;
}