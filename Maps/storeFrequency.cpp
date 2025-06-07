#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<char, int> mp;

    mp.insert({{'a', 1}, {'b', 1}, {'c', 1}, {'d', 1}, {'e', 1}, {'f', 1}});


    mp['a']++;
    for(const auto& pair : mp){
        cout << pair.first << " " << pair.second << endl;
    }

    return 0;
}