#include <iostream>
#include <vector>
using namespace std;


vector<int> deleteDuplicate(vector<int>& arr, int n){
    int i = 1;
    
}


int main(){
    vector<int> arr;
    int input;
    cin >> input;

    while(input != -1){
        arr.push_back(input);
        cin >> input;
    }

    vector<int> result = deleteDuplicate(arr, arr.size());
    for(int num : result){
        cout << num << " ";
    }
    cout << endl;


    return 0;
}