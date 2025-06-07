#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int, int>> findPairs(vector<int>& nums1, vector<int>& nums2, int target){
    vector<pair<int, int>> ans;
    unordered_map<int, int> seen;
    for(int& num : nums1){
        int complement = target - num;  
        seen[complement] = num;
    }

    for(int& num : nums2){
        if(seen.find(num) != seen.end()){
            ans.push_back({seen[num], num});
        }
    }

    if(ans.size() == 0){
        ans.push_back({-1, -1});
    }

    return ans;
}

void printPairs(vector<pair<int, int>>& pairs){
    cout << "Pairs:" << endl;
    for(const auto& it : pairs){
        cout << it.first << " " << it.second << endl;
    }
}

int main(){
    system("cls");

    vector<int> vec1;
    vector<int> vec2;

    int input;
    cin >> input;

    while(input != -1){
        vec1.push_back(input);
        cin >> input;
    }

    cin >> input;
    while(input != -1)
    {
        vec2.push_back(input);
        cin >> input;
    }

    int target;
    cin >> target;

    vector<pair<int, int>> pairs = findPairs(vec1, vec2, target);
    printPairs(pairs);




    return 0;
}