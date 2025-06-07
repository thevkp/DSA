#include <iostream>
#include <vector>
using namespace std;


vector<int> countOccurence(vector<int>& arr, int k, int x){
    vector<int> ans;
    int r = k - 1;
    int n = arr.size();
    for(int i = 0; i < n && r < n; i++, r++){
        int count = 0;
        while(i <= r){
            if(arr[i] == x){
                count++;
            }
            i++;
        }
        ans.push_back(count);
        i = i - k;
    }

    return ans;
}


int main(){ 
    system("cls");

    int n;
    cin >> n;

    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    int x, k;
    cin >> k >> x;

    vector<int> occX = countOccurence(vec, k, x);
    for(int& x : occX){
        cout << x << " ";
    }





    return 0;
}


// 8
// 1 3 3 4 3 2 8 3
// 3 3