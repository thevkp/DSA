#include <iostream>
#include <vector>
using namespace std;


const int MAX  = 1e6 + 1;
vector<int> isPrime(MAX, true);

void sieve(){
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i < MAX; i++){
        if(isPrime[i]){
            for(int j = i * i; j < MAX; j += i){
                isPrime[j] = false;
            }
        }
    }
}

bool checkPrime(int n){
    return isPrime[n];
}


int main(){
    system("cls");

    sieve();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cout << boolalpha;
        cout << checkPrime(n) << endl;
    }


    return 0;
}