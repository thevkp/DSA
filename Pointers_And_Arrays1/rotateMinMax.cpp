#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int>& arr, int start, int end){
    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}


void rotate(vector<int>& arr, int n, int k){
    k = k % n;
    reverse(arr, 0, n - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
}


pair<int, int> maxMin(vector<int>& arr, int n, int k){
    rotate(arr, n, k);

    int max = arr[0];
    int min = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min){
            min = arr[i];
        }
    }

    return make_pair(min, max);
}

int main(){
    vector<int> arr;
    int input;
    cin >> input;

    while(input != -1){
        arr.push_back(input);
        cin >> input;
    }

    int k;
    cin >> k;


    pair<int, int> ans = maxMin(arr, arr.size(), k);
    cout << ans.first << " " << ans.second << endl;

    return 0;
}