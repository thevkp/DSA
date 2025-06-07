#include <iostream>
#include <vector>
using namespace std;


int maxOnes(vector<int>& arr, int k){
    int maxOnes = 0;

    int r = k - 1;
    int n = arr.size();

    for(int l = 0; l < n && r < n; l++, r++){
        int ones = 0;
        int i = l;
        while(i <= r){
            if(arr[i] == 1){
                ones++;
            }
            i++;
        }
        // cout << maxOnes << endl;
        maxOnes = ones > maxOnes ? ones : maxOnes;
    }

    return maxOnes;
}


int main(){
    system("cls");

    vector<int> vec;

    int input;
    cin >> input;

    while(input != -1){
        vec.push_back(input);
        cin >> input;
    }

    int k;
    cin >> k;

    cout << maxOnes(vec, k) << endl;




    return 0;
}