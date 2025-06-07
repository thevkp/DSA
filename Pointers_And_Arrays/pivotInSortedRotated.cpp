#include <iostream>
#include <vector>
using namespace std;


int findPivot(vector<int>& nums){
    int start = 0;
    int end = nums.size() - 1;

    while(start < end){
        int mid = start + (end - start) / 2;

        if(nums[mid] < nums[end])
            end = mid;
        else
            start = mid + 1;
    }

    return nums[start];
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

    return 0;
}