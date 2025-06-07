#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& vec){
    int n = vec.size();
    int i = 0;
    for(int j = 0; j < n; j++){
        if(vec[j] != 0){
            swap(vec[j], vec[i++]);
        }
    }
}

int main(){
    vector<int> vec;
    int input;
    cin >> input;
    while(input != -1){
        vec.push_back(input);
        cin >> input;
    }

    moveZeroes(vec);
    for(int& num : vec){
        cout << num << " ";
    }


    return 0;
}