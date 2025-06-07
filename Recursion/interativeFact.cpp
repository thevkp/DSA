#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int fact = 1;
    while(N){
        fact *= N;
        N = N - 1;
    }

    cout << fact << endl;

    return 0;
}