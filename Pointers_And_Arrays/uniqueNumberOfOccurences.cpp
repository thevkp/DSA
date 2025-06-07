#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

bool hasUniqueOccurences(int arr[], int n){
    unordered_map<int, int> frequencyMap;

    for(int i = 0; i < n; i++){
        frequencyMap[arr[i]]++;
    }

    set<int> freq;
    for(const auto& it : frequencyMap){
        if(freq.find(it.second) != freq.end()){
            return false;
        }
        freq.insert(it.second);
    }

    return true;
}


int main(){
    int size;
    cin >> size;

    int* arr = new int[size];

    int input;
    for(int i = 0; i < size; i++){
        cin >> input;
        arr[i] = input;
    }

    cout << boolalpha;
    cout << hasUniqueOccurences(arr, size) << endl;


    return 0;
}