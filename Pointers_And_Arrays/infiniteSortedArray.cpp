#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// brute approach
int searchInfiniteArray(vector<int>& arr, int key){
    int low = 0;
    int high = 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return -1;
}

// better approach

int getElement(vector<int>& arr, int index){
    if(index < arr.size())
        return arr[index];
    
    return INT_MAX;
}

int binarySearch(vector<int>& arr, int key){

    int low = 0;
    int high = 1;

    while(getElement(arr, high) < key){
        low = high;
        high = 2 * high;
    }
    while(low <= high){
        int mid = low + (high - low) / 2;
        int midValue = getElement(arr, mid);

        if(midValue == key)
            return mid;
        else if(mid < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main(){
    system("cls");

    vector<int> arr;
    
    int input;
    cin >> input;
    while(input != -1){
        arr.push_back(input);
        cin >> input;
    }

    int target;
    cin >> target;

    // cout << searchInfiniteArray(arr, target) << endl;
    // cout << findRange(arr, target) << endl;
    cout << binarySearch(arr, target) << endl;


    return 0;
}