#include <iostream>
#include <vector>
#include <deque>
#include <bitset>

using namespace std;

// Raise MAX so it includes large inputs like 999983
const int MAX = 1e6 + 10;
bitset<MAX> isPrime;

void sieve(){
    isPrime.set();
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i * i <= MAX; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= MAX; j += i){
                isPrime[j] = false;
            }
        }
    }
}

vector<vector<int>> findPrimes(const vector<int>& arr, int k){
    vector<vector<int>> ans;
    sieve();

    deque<int> dq; // stores indices instead of values

    // First window
    for(int i = 0; i < k; i++){
        if(arr[i] < MAX && isPrime[arr[i]]) dq.push_back(i);
    }

    // Store the first window's primes
    vector<int> temp;
    for(int idx : dq) temp.push_back(arr[idx]);
    ans.push_back(temp);

    // Sliding window
    for(int i = k; i < arr.size(); i++){
        if(arr[i] < MAX && isPrime[arr[i]]) dq.push_back(i);

        // Remove elements that are out of the current window
        if(!dq.empty() && dq.front() <= i - k) dq.pop_front();

        temp.clear();
        for(int idx : dq) temp.push_back(arr[idx]);
        ans.push_back(temp);
    }

    return ans;
}

int main(){
    // system("cls"); // Skip for debugging, causes issues in non-Windows environments

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> vec(n);
        for(int i = 0; i < n; i++){
            cin >> vec[i];
        }

        int k;
        cin >> k;

        vector<vector<int>> ans = findPrimes(vec, k);

        int i = 0;
        for(const vector<int>& row : ans){
            cout << "window " << i++ << " : ";
            for(const int& val : row){
                cout << val << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
