#include <iostream>
#include <vector>
using namespace std;

bool linearSearch(vector<int>& s, int key, int start, int end){
    if(start == end)
        return false;
    
    if(s[start] == key)
        return true;
    
    return linearSearch(s, key, start + 1, end);
}

int main(){
    vector<int> arr;
    int input;
    cin >> input;
    while(input != -1){
        arr.push_back(input);
        cin >> input;
    }

    int key;
    cin >> key;

    cout << boolalpha;
    cout << linearSearch(arr, key, 0, arr.size()) << endl;


    return 0;
}