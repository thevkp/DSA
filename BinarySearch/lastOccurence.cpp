#include <iostream>
#include <vector>
using namespace std;


int lastOccurence(vector<int>& arr, int n, int key){
    int start = 0;
    int end = n - 1;

    int lastOcc = -1;
    while(start <= end){
        int mid = start + (end - start) / 2;

        if(arr[mid] == key){
            lastOcc = mid;
            start = mid + 1;
        }
        else if(arr[mid] < key){
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    return lastOcc;
}

int main(){
    int size;
    cin >> size;

    vector<int> arr(size);
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    int target;
    cin >> target;
    
    cout << lastOccurence(arr, size, target) << endl;

    return 0;
}