#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(vector<int>& arr, int start, int end, int key){
    int mid = start + (end - start) / 2;
    
    if(arr[mid] == key)
        return true;
    else if(arr[mid] > key)
        binarySearch(arr, mid + 1, end, key);
    else    
        binarySearch(arr, start, mid - 1, end);

    return false;
}

int main(){
    vector<int> arr;
    int input;
    cin >> input;
    while(input != -1){
        arr.push_back(input);
        cin >> input;
    }

    int key;
    cin >> key;

    cout << boolalpha;
    cout << binarySearch(arr, 0, arr.size(), key) << endl;

    return 0;
}

