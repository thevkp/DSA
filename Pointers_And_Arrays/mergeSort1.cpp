#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums, int low, int mid, int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> left(n1), right(n2);

    for(int i = 0; i < n1; i++){
        left[i] = nums[low + i];
    }
    for(int i = 0; i < n2; i++){
        right[i] = nums[mid + i + 1];
    }

    int i = 0, j = 0, k = low;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            nums[k] = left[i];
            i++;
        }
        else{
            nums[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        nums[k] = left[i];
        i++;
        k++;
    }

    while(j < n2){
        nums[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& nums, int low, int high){
    if(low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    merge(nums, low, mid, high);
}

void printArray(vector<int> arr){
    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    system("cls");

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    printArray(arr);
    mergeSort(arr, 0, n - 1);
    printArray(arr);

    return 0;
}