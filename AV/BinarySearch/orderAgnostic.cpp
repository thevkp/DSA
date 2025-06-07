#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int orderAgnostic(const vector<int>& arr, int key){
    int start = 0;
    int end = arr.size() - 1;

    while(start <= end){
        int mid = start + (end - start) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int main(){
    system("cls");

    vector<int> vec;

    int input;
    cin >> input;
    while(input != -1){
        vec.push_back(input);
        cin >> input;
    }

    sort(vec.begin(), vec.end(), greater<int>());

    int target;
    cin >> target;
    for(const int& num : vec){
        cout << num << " ";
    }
    cout << endl;

    cout << orderAgnostic(vec, target) << endl;



    return 0;
}