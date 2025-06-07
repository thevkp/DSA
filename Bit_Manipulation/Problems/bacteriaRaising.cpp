#include <iostream>
using namespace std;

int minBacteria(int n ){
    return __builtin_popcount(n);
}


int main(){
    system("cls");


    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cout << minBacteria(n) << endl;
    }




    return 0;
}