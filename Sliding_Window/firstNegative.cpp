#include <iostream>
#include <vector>
using namespace std;


vector<int> firstNegatives(vector<int>& arr, int& k){
    vector<int> ans;

    int n = arr.size();
    int r = k - 1;

    for(int i = 0; i < n && r < n; i++, r++){
        int l = i;
        while(l < r){
            if(arr[l] < 0){
                ans.push_back(arr[l]);
                break;
            }
            l++;
        }
        if(l == r){
            ans.push_back(0);
        }
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

    int k;
    cin >> k;

    vector<int> result = firstNegatives(vec, k);

    for(int& num : result){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// 8
// 12 -1 -7 8 -15 30 16 28
// 3