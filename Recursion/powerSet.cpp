#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& arr, vector<int> output, int index, vector<vector<int>>& ans){
    if(index >= arr.size()){
        ans.push_back(output);
        return;
    }

    // exclude
    solve(arr, output, index + 1, ans);

    // include
    int element = arr[index];
    output.push_back(element);
    solve(arr, output, index + 1, ans);
}

vector<vector<int>> powerSet(vector<int> arr){
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(arr,output, index, ans);
    return ans;
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

    vector<vector<int>> ans = powerSet(arr);

    for(const auto& num : ans){
        for(int val : num){
            cout << val << " ";
        }
        cout << endl;
    }


    return 0;
}