#include <iostream>
#include <vector>
using namespace std;


pair<int, int> subWithMaxSum(vector<int>& arr, int k){
    pair<int, int> ans;

    int windowSum = 0;
    int i;
    for(i = 0; i < k; i++){
        windowSum = windowSum + arr[i];
    }

    int maxSum = windowSum;
    ans.first = 0;
    ans.second = i - 1;
    
    cout << "wsum: " << windowSum << " " << "maxSum: " << maxSum << endl;
    for(int i = k; i < arr.size(); i++){
        windowSum = windowSum + arr[i] - arr[i - k];
        if(windowSum > maxSum){
            ans.first = i - k + 1;
            ans.second = i;
            maxSum = windowSum;
        }
        cout << "wsum: " << windowSum << " " << "maxSum: " << maxSum << endl;
    }

    return ans;
}


int main(){
    system("cls");

    int n;
    cin >> n;

    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }


    int k;
    cin >> k;

    pair<int, int> subarray = subWithMaxSum(vec, k);

    for(int i = subarray.first; i <= subarray.second; i++){
        cout << vec[i] << " ";
    }
    cout << endl;



    return 0;
}


// 8
// 1 3 7 8 2 -4 5 21
// 3