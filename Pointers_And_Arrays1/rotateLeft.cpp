#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int>& arr, int start, int end){
    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotate(vector<int>& arr, int n, int k){
    k = k % n;

    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
    reverse(arr, 0, n - 1);
    // reverse(arr, 0, n - 1);
    // reverse(arr, 0, k);
    // reverse(arr, k + 1, n - 1);
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

    int k;
    cin >> k;
    rotate(arr, arr.size(), k);

    printArr(arr);

    return 0;
}