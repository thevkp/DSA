#include <iostream>
#include <vector>
using namespace std;

vector<int> subset(vector<int>& arr, int start, int end){
    vector<int> ans;
    if(start >= end)
        return ans;
    
    ans.push_back(arr[start]); 
    subset(arr, start + 1, end);
    return ans;
}

vector<int> findSub(vector<int>& arr, int n){   
    vector<int> ans = subset(arr, 0, n);
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

    vector<int> sub  = findSub(arr, 3);
    for(int num : sub){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}