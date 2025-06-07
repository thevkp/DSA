#include <iostream>
#include <vector>
#include <deque>
#include <bitset>

using namespace std;


const int MAX = 1e6 + 1;
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

vector<vector<int>> findPrimes(vector<int>& arr, int k){
    vector<vector<int>> ans;
    sieve();

    // vector<int> temp;
    deque<int> dq;
    for(int i = 0; i < k; i++){
        if(isPrime[arr[i]]) dq.push_back(arr[i]);
    }

    ans.emplace_back(dq.begin(), dq.end());
    for(int i = k; i < arr.size(); i++){
        if(isPrime[arr[i]]) dq.push_back(arr[i]);
        // if(isPrime[arr[i]] && isPrime[arr[i - k]]) dq.pop_front();
        // if(!isPrime[arr[i]]) dq.pop_front();  
        if(isPrime[arr[i - k]]){
            if(!dq.empty() && dq.front() == arr[i - k]){
                dq.pop_front();
            }
        }
        ans.emplace_back(dq.begin(), dq.end());
    }

    // ans.push_back(temp);
    return ans;
}


int main(){
    system("cls");


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