#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// using find(), T.C O(n)  S.C O(n)
vector<int> deleteDuplicates(vector<int>& arr, int n){
    // unordered_map<int, int> frequencyMap;
    vector<int> ans;
    for(int num : arr){
        if(!(find(ans.begin(), ans.end(), num) != ans.end())){
            ans.push_back(num);
        }
    }

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

    vector<int> noDuplicates = deleteDuplicates(arr, arr.size());
    for(const auto& num : noDuplicates){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}