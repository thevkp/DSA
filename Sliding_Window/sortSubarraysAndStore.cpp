#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> sortSubarrays(const vector<int>& arr, int k) {
    vector<vector<int>> result;
    for (int i = 0; i <= arr.size() - k; ++i) {
        vector<int> temp(arr.begin() + i, arr.begin() + i + k);
        sort(temp.begin(), temp.end());
        result.push_back(temp);
    }
    return result;
}



int main(){
    system("cls");

    int n;
    cin >> n;

    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    int k;
    cin >> k;
    vector<vector<int>> ans = sortSubarrays(vec, k);

    int i = 0;
    for(const auto& rows : ans){
        cout << "Subarray: " << i << " : "; 
        i++;
        for(const int& val : rows){
            cout << val << " ";
        }
        cout << endl;
    }



    return 0;
}

// 8
// 3 2 -1 4 3 2 8 3
// 3

// 8
// 3 2 -1 -5 3 2 8 3
// 3 