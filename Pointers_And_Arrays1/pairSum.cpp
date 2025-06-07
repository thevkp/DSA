#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;


// T.C: O(n^2), S.C: O(1)
vector<pair<int,int>> findPairs(vector<int>& nums, int target){
    int n = nums.size();
    vector<pair<int, int>> ans;
    bool pairFound = false;
    for(int i = 0; i < n - 1; i++){
        for(int j = i; j < n - 1; j++){
            if(nums[i] + nums[j] == target){
                ans.push_back(make_pair(nums[i], nums[j]));
                pairFound = true;
            }
        }
    }

    if(pairFound)
        return ans;
    else{
        ans.push_back(make_pair(-1, -1));
        return ans;
    }
}

// T.C: O(nlogn) S.C: O(n)
vector<pair<int,int>> findPairs1(vector<int>& nums, int target){
    sort(nums.begin(), nums.end());
    unordered_map<int, int> seen;
    vector<pair<int, int>> ans;
    
    for(int num : nums){
        int complement = target - num;
        // seen[num]++;
        if(seen.find(complement) != seen.end() && seen[complement] >= 1){
            ans.push_back({complement, num});
            seen[num]--;
        }
        seen[num]++;
    }

    if(ans.size() == 0)
        ans.push_back({-1, -1});
    return ans;
}

// T.C: O(n) S.C: O(n);
vector<pair<int, int>> findPairs2(vector<int>& nums, int target){
    unordered_map<int, int> seen;
    vector<pair<int, int>> ans;

    for(int num : nums){
        int complement = target - num;
        if(seen[complement] > 0){
            ans.push_back({complement, num});
            seen[num]--;
        }
        else{
            seen[num]++;
        }
    }

    if(ans.size() == 0){
        ans.push_back({-1, -1});
    }

    return ans;
}


// No duplicates 
vector<pair<int, int>> findPairsNoDuplicates(vector<int>& nums, int target){
    unordered_map<int, int> seen;
    vector<pair<int, int>> ans;

    for(int num : nums){
        int complement = target - num;
        if(seen[complement] > 0 && complement != num){
            ans.push_back({complement, num});
            seen[num]--;
        }
        else{
            seen[num]++;
        }
    }

    if(ans.size() == 0){
        ans.push_back({-1, -1});
    }

    return ans;
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

    vector<pair<int, int>> pairs = findPairs(vec, target);
    cout << "All with self summation:" << endl;
    for(const auto& it : pairs){
        cout << it.first << " " << it.second << endl;
    }

    cout << "Pairs1:" << endl;
    vector<pair<int, int>> pairs1 = findPairs1(vec, target);
    for(const auto& it : pairs1){
        cout << it.first << " " << it.second << endl;
    }


    cout << "Pairs2:" << endl;
    vector<pair<int, int>> pairs2 = findPairs2(vec, target);
    for(const auto& it : pairs2){
        cout << it.first << " " << it.second << endl;
    }


    cout << "Unique value pairs:" << endl;
    vector<pair<int, int>> pairs3 = findPairsNoDuplicates(vec, target);
    for(const auto& it : pairs3){
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}