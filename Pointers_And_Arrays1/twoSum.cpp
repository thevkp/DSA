#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;

// T.C O(n^2), S.C (1);
pair<int, int> findPair(vector<int>& nums, int k){
    for(int i = 0; i <  nums.size(); i++){
        for(int j = i; j < nums.size(); j++){
            if(nums[j] + nums[i] == k){
                return  make_pair(nums[i], nums[j]);
            }
        }
    }
    return  make_pair(-1, -1);
}

// T.C O(nlogn), S.C O(1);
pair<int, int> findPair1(vector<int>& nums, int k){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int i = 0, j =  n - 1;
    while(i < n && j >= 0){
        int sum = nums[i] + nums[j];
        if(sum == k){
            return  make_pair(nums[i], nums[j]);
        }
        else if(sum > k){
            j--;
        }
        else {
            i++;
        }
    }
    return {-1, -1};
}

// T.C  O(n), S.C O(n);
pair<int, int> findPair2(vector<int>& nums, int k){
    unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); i++){
        int complement = k - nums[i];
        if(map.find(complement) != map.end()){
            return make_pair(map[complement], nums[i]);
        }
        map[nums[i]] = i;
    }
    return {-1, -1};
}


int  main(){
    system("cls");

    vector<int> vec;

    int input, target;
    cin >> input;

    while(input != -1){
        vec.push_back(input);
        cin >> input;
    }

    cin >> target;
    
    pair<int, int> twoIndices = findPair(vec, target);
    cout <<  twoIndices.first << " " << twoIndices.second << endl;
    pair<int, int> twoIndices1 = findPair1(vec, target);
    pair<int, int> twoIndices2 = findPair2(vec, target);
    cout <<  twoIndices1.first << " " << twoIndices1.second << endl;
    cout <<  twoIndices2.first << " " << twoIndices2.second << endl;


    return 0;
}