#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;


vector<pair<int, int>> twoSumIndices(vector<int>& arr, int k){
    vector<pair<int, int>> ans;

    unordered_map<int, int> map;
    for(int i = 0; i < arr.size(); i++){
        int complement = k - arr[i];
        if(map.find(complement) != map.end()){
            ans.push_back(make_pair(i, ))
        }
    }
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

    int target;
    cin >> target;

    vector<pair<int, int>> indices = twoSumIndices(vec, target);


    return 0;
}