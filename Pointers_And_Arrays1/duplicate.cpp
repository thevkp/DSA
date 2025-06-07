/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Example 2:

Input: nums = [1,2,3,4]

Output: false

Explanation:

All elements are distinct.

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true
*/





#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


bool containsDuplicate(vector<int>& nums){
    unordered_map<int, int> freqMap;
    for(int num : nums){
        if(freqMap.count(num) >= 1)
            return true;
        freqMap[num]++;
    }

    return false;
}


int main(){ 
    vector<int> arr;
    int input;
    cin >> input;
    while(input != -1){
        arr.push_back(input);
        cin >> input;
    }

    cout << boolalpha;
    cout << containsDuplicate(arr) << endl;


    return 0;
}