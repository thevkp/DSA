#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& nums, int index, vector<int> output, vector<vector<int>>& ans){
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }

    // exclude
    solve(nums, index + 1, output, ans);

    // include
    int element = nums[index];
    output.push_back(element);
    solve(nums, index + 1, output, ans);
}

vector<vector<int>> powerSet(vector<int>& nums){
    int index = 0;
    vector<vector<int>> ans;
    vector<int> output;
    
    solve(nums, index, output, ans);
    return ans;
}

int main(){
    vector<int> arr;
    int input;
    cin >> input;
    while(input != -1){
        arr.push_back(input);
        cin >> input;
    }

    vector<vector<int>> ans = powerSet(arr);
    for(const auto& set : ans){
        for(int elements : set){
            cout << elements << " ";
        }
        cout << endl;
    }

    return 0;
}