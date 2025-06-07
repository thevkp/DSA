#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


void input(vector<int>& arr){
    srand(time(0));
    while(rand() % 10000 != rand() % 10000){
        if(arr.size() >= 1000000)
            break;
        arr.push_back(rand() % 11);
    }
}

unordered_map<int, int> storeNGetFreq(vector<int>& arr){
    unordered_map<int, int> mp;
    for(auto num : arr){
        mp[num]++;
    }

    for(const auto& it : mp){
        cout << it.first << " : " << it.second << endl;
    }
    cout << endl;

    return mp;
}

int highestFrequency(unordered_map<int, int>& mp){
    int maxFreq = INT_FAST32_MIN;
    int key = -1;

    for(const auto& it : mp){
        if(maxFreq < it.second){
            maxFreq = it.second;
            key = it.first;
        }
    }
    return key;
}

void printArr(vector<int>& arr){
    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    system("cls");
    vector<int> arr;

    input(arr);
    printArr(arr);
    unordered_map<int, int> freq = storeNGetFreq(arr);

    int key = highestFrequency(freq);

    cout << key << " : " << freq[key] << endl;

    return 0;
}