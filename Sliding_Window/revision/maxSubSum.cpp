#include <iostream>
#include <vector>
using namespace std;

int maxSubSum(vector<int>& arr, int k){
    int windowSum = 0;
    for(int i = 0; i < k; i++){
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    for(int i = k; i < arr.size(); i++){
        windowSum = windowSum + arr[i] - arr[i - k];
        maxSum = max(windowSum, maxSum);
    }

    return maxSum;
}



int main(){
    system("cls");

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << maxSubSum(arr, k) << endl;

    




    return 0;
}


// 8
// 1 3 7 8 2 -4 5 3
// 3