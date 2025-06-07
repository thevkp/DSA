#include <iostream>
using namespace std;


int main(){
    // arr[i][j] = c * i + j
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    cout << *(*(arr + 3 * 1 + 2)) << endl;

    return 0;
}