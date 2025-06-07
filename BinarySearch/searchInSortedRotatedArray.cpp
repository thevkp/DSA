#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int>& arr, int start, int end){
    while(start < end){
        int mid = start + (end - start) / 2;

        if(arr[mid] < arr[end])
            end = mid;
        else
            start = mid + 1;
    }

    return start;
}

int binarySearch(vector<int>& arr, int start, int end, int key){
    int mid = start + (end - start) / 2;
    while(start <= end){
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int search(vector<int>& arr, int key){
    int n = arr.size();

    int start = 0;
    int end = n - 1;
    int pivot = findPivot(arr, start, end);

    return binarySearch()

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

    cout << search(arr, target) << endl;


    return 0;
}