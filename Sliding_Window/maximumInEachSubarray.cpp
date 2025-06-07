#include <iostream>
#include <vector>
#include <climits>
using namespace std;


vector<int> maxInSubarrays(vector<int>& arr, int k){
    vector<int> ans;

    int maxi = INT_MIN;
    int i;
    for(i = 0; i < k; i++){
        if(arr[i] > maxi){
            maxi = arr[i];
        }
    }

    ans.push_back(maxi);
    for(i = i - k + 1; i < arr.size(); i++){
        if(arr[i] > maxi){
            ans.push_back(arr[i]);
        }
    }

    return ans;
}

// vector<int> maxInSubarrays(vector<int>& arr, int k){
//     vector<int> ans;

//     int maxi = INT_MIN;
//     int i = 0, j = 0;

//     while(j < arr.size()){
//         if(maxi < arr[j])
//             maxi = arr[j];
//         if(j - i + 1 < k){
//             j++;
//         }

//         if(j - i + 1 == k){
//             if(arr[i] > arr[j]){
//                 maxi = arr[i];
//             }
//             i++;
//             j++;
//         }

//     }   
// }



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

    vector<int> result = maxInSubarrays(vec, k);
    for(int& val : result){
        cout << val << " ";
    }
    cout << endl;



    return 0;
}


// 8
// 1 3 -1 -3 5 3 6 7 
// 3