#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findRepeated(vector<int>& arr){
    vector<int> ans;
    unordered_map<int, int> freq;

    for(int& num : arr){
        freq[num]++;
        if(freq[num] == 2)
            ans.push_back(num);
    }

    // for(auto& it : freq){
    //     cout << it.first << " " << it.second << endl;
    // }

    // for(auto& it : freq){
    //     if(it.second == 2)
    //         ans.push_back(it.first);
    // }

    return ans;
}


int main(){
    system("cls");

    int size;
    cin >> size;
    vector<int> arr(size);

    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    vector<int> repEl = findRepeated(arr);
    for(int& num : repEl){
        cout << num << " ";
    }
    cout << endl;


    return 0;
}