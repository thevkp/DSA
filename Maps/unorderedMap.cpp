// Time complexity O(1)

#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<char, int> mp;

    mp.insert({'a', 1});
    mp.insert({{'e', 6}, {'f', 7}});

    for(const auto& pair : mp){
        cout << pair.first << " " << pair.second << endl;
    }

    return 0;
}