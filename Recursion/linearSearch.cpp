#include <iostream>
using namespace std;

bool ls(int arr[], int n, int x, int start) {
    if(start == n) return false;

    if(arr[start] == x) return true;
    else {
        bool isPresent = ls(arr, n, x, start + 1);
        return isPresent;
    }
}

int lsIdx(int arr[], int n, int x, int start){
    if(start == n) return -1;

    if(arr[start] == x) return start;
    else {
        int idx = lsIdx(arr, n, x, start + 1);
        return idx;
    }
}

bool bs(int arr[], int start, int end, int target) {
    if(start > end) return false;

    int mid = start + (end - start) / 2;

    if(arr[mid] == target) return true;
    if(arr[mid] > target){
        return bs(arr, start, mid - 1, target);
    }
    else {  
        return bs(arr, mid + 1, end, target); 
    }
}


int main(){
    system("cls");

    int size, i = 0, input;
    cin >> size;

    int arr[size];

    cin >> input;
    while(i < size && input != -1){
        arr[i] = input;
        cin >> input;
        i++;
    }

    int target;
    cin >> target;

    cout << boolalpha;
    cout << ls(arr, size, target, 0) << endl;
    cout << lsIdx(arr, size, target, 0) << endl;
    cout << bs(arr, 0, size - 1, target) << endl;



    return 0;
}