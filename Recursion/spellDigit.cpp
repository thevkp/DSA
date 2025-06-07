#include <iostream>
using namespace std;

string arr[10] = {"zero","one","two","three","four","five"
                   ,"six","seven","eight","nine"};


void spell(int n){
    
    if(n == 0)
        return;

    int digit = n % 10;

    spell(n / 10);
    cout << arr[digit] << endl;
}

int main(){
    int N;
    cin >> N;

    spell(N);

    return 0;
}