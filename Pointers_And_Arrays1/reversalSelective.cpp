#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int>& arr, int n, int k){
    int start = 0;
    int end = n - 1;
    while(start < end){
        if(start == k){
            start++;
        }
        else if(end == k){
            end--;
            continue;
        }
        // if(start < end && start != k && end != k){
        //     swap(arr[start], arr[end]);
        //     start++;
        //     end--;
        // }
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
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
    reverse(arr, arr.size(), k);
    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}