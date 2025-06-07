#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int>& arr){
    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;
}


void reverse(vector<int>& arr, int start, int end){
    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotateEveryOther(vector<int>& arr, int n, int k){
    int evenSize = (n + 1) / 2;
    // int evenSize = n & 1 ? (n / 2) + 1 : (n / 2);
    vector<int> even(evenSize);

    k = k % evenSize;
    
    int j = 0;
    for(int i = 0; i < n; i++){
        if(!(i & 1)){
            even[j] = arr[i];
            ++j;
        }
    }

    reverse(even, 0, evenSize - 1);
    reverse(even, 0, k - 1);
    reverse(even, k, evenSize - 1);

    j = 0;
    for(int i = 0; i < n; i++){
        if(!(i & 1)){
            arr[i] = even[j];
            ++j;
        }
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


    rotateEveryOther(arr, arr.size(), k);
    printArr(arr);


    return 0;
}