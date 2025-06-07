#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void sortSubarrays(vector<int>& arr, int k){
    sort(arr.begin(), arr.begin() + k);

    for(int i = 1; i < arr.size() - k; i++){
        sort(arr.begin() + i, arr.begin() + k + i);
    }
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
    sortSubarrays(vec, k);

    for(int& num : vec){
        cout << num << " ";
    }
    cout << endl;



    return 0;
}

// 8
// 3 2 -1 4 3 2 8 3
// 3

// 8
// 3 2 -1 -5 3 2 8 3
// 3 