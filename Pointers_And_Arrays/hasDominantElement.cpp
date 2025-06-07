#include <bits/stdc++.h>
using namespace std;

// bool hasDominant(int* arr, int size){
//     int freq[size] = {0};
    
//     for(int i = 0; i < size; i++){
//         freq[arr[i]]++;
//     }
    

//     for(int i = 0; i < size - 1; i++){
//         if((freq[i] > freq[i + 1] || freq[i] < freq[i + 1]) && (freq[i] != 0 && freq[i + 1] != 0)){
//             return true;
//         }
//     }
    
//     return false;
// }

bool hasDominant(int* arr, int size){
    unordered_map<int, int> freq;

    for(int i = 0; i < size; i++){
        freq[arr[i]]++;
    }

    for(const auto& it : freq){
        cout << it.first << " : " << it.second << endl;
    }

    int maxFreq = 0;
    int maxFreqCount = 0;
    for(const auto& it : freq){
        if(maxFreq < it.second){
            maxFreq = it.second;
            maxFreqCount = 1;
        }
        else if(maxFreq == it.second)
            maxFreqCount++;
    }

    return maxFreqCount == 1;
}

int main() {
	// your code goes here
    int t;
    cin >> t;
    
    while(t--){
        int size;
        cin >> size;
        
        int* arr = new int[size];
        for(int i = 0; i < size; i++){
            cin >> arr[i];
        }
        
        if(hasDominant(arr, size))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
        delete[] arr;
    }
    
    return 0;
}
