#include <iostream>
#include <unordered_map>
using namespace std;

bool unique(int arr[], int n) {
    unordered_map<int, int> freq;
    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    for(const auto& pair : freq){
        cout << pair.first << " : " << pair.second << endl;
    }

    return true;
}

int main(){
    system("cls");
    
    int arr[] = {1,1,3,3,3,5,7,7,7,7};
    int size = sizeof(arr) / sizeof(arr[0]);

    bool ans = unique(arr, size);


    return 0;
}