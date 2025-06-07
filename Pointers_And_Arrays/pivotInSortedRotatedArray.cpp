#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int>& nums, int index = 0){
    int n = nums.size();
    int start = 0, end = n - 1;
    while(start < end){
        int mid = start + (end - start) / 2;

        if(nums[mid] >= nums[end])
            start = mid + 1;
        else
            end = mid;
    }

    return !index ? nums[start] : start;
}

bool binarySearch(vector<int>& nums, int target, int start, int end){
    while(start < end){
        int mid = start + (end - start) / 2;

        if(nums[mid] == target)
            return true;
        else if(nums[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return false;
}

bool searchRotated(vector<int>& nums, int target){
    int pivot = findPivot(nums, 1);
    
    return binarySearch(nums, target, 0, pivot - 1) || binarySearch(nums, target, pivot, nums.size() - 1);
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

    cout << findPivot(vec) << endl;

    int target;
    cin >> target;

    cout << boolalpha;
    cout << searchRotated(vec, target) << endl;

    return 0;
}