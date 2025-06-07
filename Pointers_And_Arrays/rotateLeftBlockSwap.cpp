#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int>& arr){
    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;
}

void blockSwap(vector<int>& arr, int n, int k){
    if(k == 0 || k == n) return; // no rotation needed
    k = k % n;
    vector<int> right(k);
    vector<int> left(n - k);

    // copy the first n - k elements to left block(vector)
    for(int i = 0; i < n - k; i++){
        left[i] = arr[i];
    }

    // copy the last k elements to right block(vector)
    for(int i = 0; i < k; i++){
        right[i] = arr[n - k + i];
    }

    // right part goes in the beginning
    for(int i = 0; i < k; i++){
        arr[i] = right[i];
    }

    // left part goes to the end
    for(int i = 0; i < n - k; i++){
        arr[k + i] = left[i];
    }
}

// void blockSwap(vector<int>& arr, int n, int k){
//     k = k % n;
//     vector<int> right;
//     vector<int> left;
//     for(int i = 0; i < n - k; i++){
//         right.push_back(arr[i]);
//     }
//     // printArr(right);

//     for(int j = k + 1; j < n; j++){
//         left.push_back(arr[j]);
//     }
//     // printArr(left);

//     int i = 0;
//     while(i < left.size()){
//         arr[i] = left[i++];
//     }

//     int j = 0;
//     while(j < right.size()){
//         arr[i++] = right[j++];
//     }
// }

int main(){
    system("cls");
    vector<int> arr;
    int input;
    cin >> input;
    while(input != -1){
        arr.push_back(input);
        cin >> input;
    }

    int k;
    cin >> k;

    blockSwap(arr, arr.size(), k);
    printArr(arr);

    return 0;
}