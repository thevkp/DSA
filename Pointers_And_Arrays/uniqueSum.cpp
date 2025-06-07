#include <iostream>
#include <unordered_map>
using namespace std;


int uniqueElementSum(int arr[], int n){
    unordered_map<int, int> frequencyMap;

    for(int i = 0; i < n; i++){
        frequencyMap[arr[i]]++;
    }

    int sum = 0;
    for(const auto& it : frequencyMap){
        if(it.second == 1)
            sum += it.first;
    }

    return sum;
}

int main(){
    system("cls"); 
    int size;
    cin >> size;

    int* arr = new int[size];

    int input;
    for(int i = 0; i < size; i++){
        cin >> input;
        arr[i] = input;
    }


    cout << uniqueElementSum(arr, size) << endl;

    return 0;
}