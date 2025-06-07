#include <iostream>
using namespace std;

int power(int n){
    if(n == 0)
        return 1;
        
    if(n == 1)
        return 2;
        
    return 2 * power(n - 1); 
}

int main(){
    int N;
    cin >> N;

    cout << power(N) << endl;

    return 0;
}