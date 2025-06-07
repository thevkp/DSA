#include <iostream>
#include <vector>
using namespace std;

int unique(vector<int>& arr, int n){
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans ^= arr[i];
    }

    return ans;
}

int main(){
    vector<int> arr;

    int input;
    cin >> input;

    while(input != -1){
        arr.push_back(input);
        cin >> input;
    }

    cout << unique(arr, arr.size()) << endl;



    return 0;
}


