#include <iostream>
#include <vector>
using namespace std;

// minimum moves to sort arrays is accumulation of differences betwen two consecutive
// unsorted elements
long long moves(vector<int>& arr, int n) {
    long long minMoves = 0;
    for (size_t i = 1; i < n; i++) {
        if(arr[i] < arr[i - 1]){
            minMoves += (arr[i - 1] - arr[i]);
            arr[i] = arr[i - 1];
        }
    }
    return minMoves;
}

int main() {
    int size;
    cin >> size;

    if (size <= 0) {
        cout << "Invalid size!" << endl;
        return 1;
    }

    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << moves(arr, size) << endl;
    return 0;
}
