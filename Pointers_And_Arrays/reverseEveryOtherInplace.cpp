#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int>& arr){
    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;
}


void reverseInPlace(vector<int>& arr, int start, int end){
    while(start < end){
        swap(arr[start], arr[end]);
        start += 2; // Move to the next even index
        end -= 2;   // Move to the previous even index
    }
}

void rotateEveryOtherInPlace(vector<int>& arr, int n, int k){
    // Calculate the size of even-indexed elements
    int evenSize = (n + 1) / 2;

    // Normalize k to ensure it is within bounds
    k = k % evenSize;
    
    // Reverse the even-indexed elements
    // reverseInPlace(arr, 0, (evenSize - 1) * 2);
    reverseInPlace(arr, 0, n - 1);
    // Reverse the first part (first k even indices)
    reverseInPlace(arr, 0, (k - 1) * 2);
    // Reverse the second part (the remaining even indices)
    // reverseInPlace(arr, k * 2, (evenSize - 1) * 2);
    reverseInPlace(arr, k * 2, n - 1);
}


int main(){
    vector<int> arr;
    int input;
    cin >> input;
    while(input != -1){
        arr.push_back(input);
        cin >> input;
    }


    int k;
    cin >> k;


    rotateEveryOtherInPlace(arr, arr.size(), k);
    printArr(arr);


    return 0;
}