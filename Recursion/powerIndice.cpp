#include <iostream>
using namespace std;

long long int result(long long int a, long long int b){
    if(b == 0)
        return 1;
    
    if(b == 1)
        return a;
    
    // return a * result(a, b - 1);
    int ans = result(a, b/2);

    if(!(b & 1)){
        return ans * ans;
    }
    else
        return a * ans * ans;
}


int main(){
    long long int x, y;
    cin >> x >> y;

    cout << result(x, y) << endl;

    return 0;
}