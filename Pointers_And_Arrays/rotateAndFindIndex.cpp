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


int index(vector<int>& arr, int n, int k, int element){
    rotate(arr, n, k);

    int i = 0;
    while(i < n){
        if(arr[i] == element){
            return i;
        }
        i++;
    }

    return -1;
}


bool isPresent(vector<int>& arr, int n, int x){
    for(int i = 0; i < n; i++){
        if(arr[i] == x){
            return true;
        }
    }

    return false;
}

int main(){
    vector<int> arr;
    int input;
    cin >> input;

    while(input != -1){
        arr.push_back(input);
        cin >> input;
    }

    int k, element;
    cin >> k >> element;

    if(isPresent(arr, arr.size(), element))
        cout << index(arr, arr.size(), k, element) << endl;
    else   
        cout << "Element not present." << endl;

    return 0;
}