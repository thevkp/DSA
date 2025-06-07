#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums){
    int start = 0;
    int end = nums.size() - 1;

    while(start < end){
        int mid = start + (end - start) / 2;

        if(nums[mid] > nums[end])
            start = mid + 1;
        else if(nums[mid] < nums[end])
            end = mid;
        else
            end = end - 1;
    }

    return start;
}

int binarySearch(vector<int>& nums, int target, int start, int end){
    while(start <= end){
        int mid = start + (end - start) / 2;

        if(nums[mid] == target)
            return mid;
        else if(target > nums[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int findIndex(vector<int>& nums, int target){
    int n = nums.size();
    if(n == 0) return -1;

    int pivot = findMin(nums);

    if(target >= nums[pivot] &&  target <= nums[n - 1])
        return  binarySearch(nums, target, pivot, n - 1);
    else
        return binarySearch(nums, target, 0, pivot - 1);
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

    cout << "Index: " << findMin(vec) << endl;

    int target;
    cin >> target;
    cout << findIndex(vec, target) << endl;


    return 0;
}