#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findUnique(vector<int>& arr, int n){
    unordered_map<int, int> frequencyMap;
    vector<int> uniqueElements;

    for(int num : arr){
        frequencyMap[num]++;
    }
    
    for(const auto& pair : frequencyMap){
        if(pair.second == 1){
            uniqueElements.push_back(pair.first);
        }
    }

    return uniqueElements;
}


int main(){
    vector<int> arr;
    int input;
    cin >> input;

    while(input != -1){
        arr.push_back(input);
        cin >> input;
    }

    vector<int> unique = findUnique(arr, arr.size());
    for(int num : unique){
        cout << num << " ";
    }
    cout << endl;
    cout << "Number of unique elements: " << unique.size() << endl;

    return 0;
}