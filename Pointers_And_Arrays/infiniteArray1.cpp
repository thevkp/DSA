#include <iostream>
#include <vector>
using namespace std;

// void findRange(vector<int>& arr, int& low, int& high, int key){
//     while(key > arr[high]){
//         int newStart = high + 1;
//         high = high + (high - low + 1) * 2;
//         low = newStart;
//     }
    
//     // if(key < arr[high]){
//     //     int newStart = high + 1;
//     //     high = high + (high - low + 1) / 2;
//     //     low = newStart;
//     //     return;
//     // }
// }
int binarySearch(vector<int>& arr, int start, int end, int key){
    while(start <= end){
        int mid = start + (end - start) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int findPos(vector<int>& arr, int key){
    int low = 0;
    int high = 1;

    int val = arr[0];
    while(val < key){
        low = high;
        high = 2 * high;
        val = arr[high];
    }

    return binarySearch(arr, low, high, key);
}

int findPos1(vector<int>& arr, int key){
    int low = 0;
    int high = 1;

    while(key > arr[high]){
        int newLow = high + 1;

        high = high + (high - low + 1) * 2;

        low = newLow;
    }

    return binarySearch(arr, low, high, key);
}

int main(){
    vector<int> arr;

    int input;
    cin >> input;

    while(input != -1){
        arr.push_back(input);
        cin >> input;
    }

    int target;
    cin >> target;


    cout << findPos(arr, target) << endl;
    cout << findPos(arr, target) << endl;


    return 0;
}