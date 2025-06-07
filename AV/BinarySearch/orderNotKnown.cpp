#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int orderAgnostic(vector<int>& arr, int start, int end, int key){
    while(start <= end){
        int mid = start + (end - start) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}

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

int orderNotKnown(vector<int>& arr, int key){
    int start = 0;
    int end = arr.size() - 1;

    if(arr[start] > arr[end]){
        return orderAgnostic(arr, start, end, key);
    }
    else
        return binarySearch(arr, start, end, key);

    return -1;
}


int main(){
    system("cls");

    vector<int> vec;

    int input;
    cin >> input;

    while(input != -1){
        vec.push_back(input);
        cin >> input;
    }

    int target;
    cin >> target;

    cout << orderNotKnown(vec, target) << endl;



    return 0;
}