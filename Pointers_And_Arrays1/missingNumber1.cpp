#include <iostream>
#include <vector>
using namespace std;

int missing(vector<int>& nums, int size) {
    int xorAll = 0; // XOR of all numbers from 1 to size
    int xorArr = 0; // XOR of all elements in the array

    // XOR all numbers from 1 to size
    for (int i = 1; i <= size; i++) {
        xorAll ^= i;
    }

    // XOR all elements in the input array
    for (int num : nums) {
        xorArr ^= num;
    }

    // XOR of xorAll and xorArr gives the missing number
    return xorAll ^ xorArr;
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
