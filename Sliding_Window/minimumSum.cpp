#include <iostream>
#include <climits>
using namespace std;


int maxSumSubarray(int* arr, int n, int k){
    if(k > n || k <= 0) return -1;
    int windowSum = 0;

    for(int i = 0; i < k; i++){
        windowSum += arr[i];
    }

    int minSum = windowSum;


    for(int i = k; i < n; i++){
        windowSum += arr[i] - arr[i - k];
        minSum = min(minSum, windowSum);
    }

    return minSum;
}


int main(){
    system("cls");

    int n;
    cin >> n;

    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int k;
    cin >> k;
    cout << maxSumSubarray(arr, n, k) << endl;


    return 0;
}





// 5
// 2 3 4 1 7
// 3