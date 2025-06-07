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

void rotate(vector<int>& arr, int subStart, int subEnd, int k){
    int subSize = subEnd - subStart + 1;
    k = k % subSize;

    reverse(arr, subStart, subEnd); // reverse entire subarray
    reverse(arr, subStart, subStart + k - 1); // reverse first k elements
    reverse(arr, subStart + k, subEnd); // revers last subSize - k elements

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

    int start, end;
    cin >> start >> end;
    int k;
    cin >> k;

    rotate(arr, start, end, k);
    printArr(arr);

    return 0;
}