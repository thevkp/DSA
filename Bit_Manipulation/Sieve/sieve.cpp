#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

const int MAX = 1e6 + 1;
bitset<MAX> isPrimes;
vector<int> primes;


void sieve(){
    isPrimes.set();

    isPrimes[0] = isPrimes[1] = false;

    for(int i = 2; i * i < MAX; i++){
        if(isPrimes[i]){
            for(int j = i * i; j < MAX; j += i){
                isPrimes[j] = false;
            }
        }
    }

    for(int i = 2; i <= MAX; i++){
        if(isPrimes[i])
            primes.push_back(i);
    }
}


int main(){
    system("cls");

    int t;
    cin >> t;

    sieve();
    while(t--){
        int n;
        cin >> n;

        // for(int i = 2; i <= n; i++){
        //     if(isPrimes[i])
        //         cout << i << " ";
        // }

        for(int prime : primes){
            if(prime > n) break;
            cout << prime << " ";
        }
        cout << endl;
    }

    return 0;
}