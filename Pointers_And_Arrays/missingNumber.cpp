#include <iostream>
#include <vector>
using namespace std;

int missing(vector<int>& nums, int size) {
    long long int realSum = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        realSum += nums[i];
    }

    long long int expectedSum = (size * (size + 1)) / 2;

    return expectedSum - realSum;
}

int main() {
    int n; 
    cin >> n;

    vector<int> arr; 
    int input;

    for (int i = 0; i < n - 1; i++) {
        cin >> input;
        arr.push_back(input);
    }

    cout << missing(arr, n) << endl;

    return 0;
}
