#include <iostream>
#include <vector>
#include <set>
using namespace std;


vector<int> countDistinct(vector<int>& arr, int k){
    int n = arr.size();
    vector<int> ans;

    int r = k - 1;

    for(int l = 0; (l < n && r < n); l++, r++){
        int i = l;
        set<int> s;

        while(i <= r){
            s.insert(arr[i]);
            i++;
        }
        ans.push_back(s.size());
    }

    return ans;
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


    vector<int> ans = countDistinct(vec, k);

    for(int& num : ans){
        cout << num << " ";
    }
    cout << endl;



    return 0;
}


// 1 2 1 3 4 2 3