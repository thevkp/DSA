#include <iostream>
#include <vector>
using namespace std;

vector<int> countOccurence(vector<int>& arr, int k, int x){
    int count = 0;
    vector<int> ans;
    for(int i = 0; i < k; i++){
        if(arr[i] == x){
            count++;
        }
    }

    ans.push_back(count);

    for(int i = k; i < arr.size(); i++){
        if(arr[i - k] == x) count--;
        if(arr[i] == x) count++;
        ans.push_back(count);
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

    int k, x;
    cin >> k >> x;

    vector<int> occX = countOccurence(vec, k, x);

    for(int& x : occX){
        cout << x << " ";
    }
    cout << endl;


    return 0;
}

// 8
// 1 3 3 4 3 2 8 3
// 3 3