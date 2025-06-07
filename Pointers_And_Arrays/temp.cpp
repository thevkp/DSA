#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void findPairsWithSum(const vector<int>& arr, int target) {
    unordered_map<int, int> numCount; // To store the frequency of elements
    vector<pair<int, int>> result;   // To store the pairs

    for (int num : arr) {
        int complement = target - num;

        // Check if the complement exists in the map
        if (numCount[complement] > 0) {
            result.push_back({complement, num});
            numCount[complement]--; // Decrease the count to avoid reuse
        } else {
            // Otherwise, store the current number in the map
            numCount[num]++;
        }
    }

    // Print the result
    if (result.empty()) {
        cout << "No pairs found with the target sum." << endl;
    } else {
        cout << "Pairs with target sum " << target << ":" << endl;
        for (const auto& p : result) {
            cout << "(" << p.first << ", " << p.second << ")" << endl;
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 7, 5, 14, -2, 3, 8, 4, 6, 6, 9, -1};
    int target = 12;

    findPairsWithSum(arr, target);

    return 0;
}
