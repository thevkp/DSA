#include <iostream>
using namespace std;

int main(){
    system("cls");
    int a[2][2] = {1,2,3,4};
    int* p = &a[0][0];

    cout << *p << endl;
    cout << *(p + 1) << endl;

    for(int i = 0; i < 4; i++){
        cout << *(p + i) << " ";
    }
    cout << endl;
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << a[i][j] << " ";
        }
    }
    cout << endl; 

    return 0;
}