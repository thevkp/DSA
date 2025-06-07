#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> duplicates(int arr[], int n){
    unordered_map<int, int> freq;
    for(int i = 0; i < n; i++){
        freq[arr[i]]++;
    }

    vector<int> ans;
    for(const auto& pair : freq){
        if(pair.second > 1){
            ans.push_back(pair.first);
        }
    }

    return ans;
}

// for sorted array
void duplicates1(int arr[], int n){
    for(int i = 0; i < n; i++){
        if(arr[i] == arr[i + 1])
            cout << arr[i] << " ";
    }
}

int main(){
    system("cls");

    int size;
    cin >> size;

    int* arr = new int[size];

    int input, i = 0;
    cin >> input;
    while(i < size && input != -1){
        arr[i] = input;
        cin >> input;
        i++;
    }

    vector<int> ans = duplicates(arr, size);
    for(const auto& num : ans){
        cout << num << " ";
    }   
    cout << endl;

    duplicates1(arr, size);



    return 0;
}