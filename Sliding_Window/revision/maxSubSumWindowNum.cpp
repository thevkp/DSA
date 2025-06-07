#include <iostream>
#include <vector>
using namespace std;


int windowNumber(vector<int>& arr, int k){
    int windowSum = 0;
    for(int i = 0; i < k; i++){
        windowSum += arr[i];
    }

    int maxSum = windowSum;
    int windowNumber = 1;

    for(int i = k; i < arr.size(); i++){
        windowSum = windowSum + arr[i] - arr[i - k];
        if(windowSum > maxSum){
            maxSum = windowSum;
            windowNumber = i - k + 2;
        }
    }

    return windowNumber;
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
    cout << windowNumber(vec, k) << endl;















    // for(int i = 0; i < n; i++){
    //     cout << vec[i] << " ";
    // }
    // cout << endl;

    // for(int i = 0; i < n; i++){
    //     cout << *(vec.data()) << " " << vec.data() << endl;
    // }
    // cout << endl;

    // for(int i = 0; i < n; i++){
    //     cout << *(vec.data() + i) << " " << (vec.data() + i) << endl;
    // }

    // vector<int> arr = {1,2,3,4,5};
    // int* ptr = arr.data();
    // cout << *ptr << " " << ptr << endl;
    // for(int i = 0; i < arr.size(); i++){
    //     cout << *(ptr + i) << " " << ptr + i << endl;
    // }
    
    



    return 0;
}