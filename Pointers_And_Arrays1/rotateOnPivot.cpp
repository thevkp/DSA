#include <iostream>
#include <vector>
using namespace std;


void rotate(vector<int>& arr, int n, int pivot){
    pivot = pivot % n;

    
}


void printArr(vector<int>& arr){
    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr;
    int input;
    cin >> input;
    while(input != -1){
        arr.push_back(input);
        cin >> input;
    }

    int p;
    cin >> p;
    rotate(arr, arr.size(), p);
    printArr(arr);



    return 0;
}