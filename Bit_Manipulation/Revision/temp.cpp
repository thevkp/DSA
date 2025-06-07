#include <iostream>
#include <string>
using namespace std;


int main(){
    system("cls");

    int n;
    cin >> n;

    char c = to_string(n % 4);
    cout << c << endl;



    return 0;
}