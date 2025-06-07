#include <iostream>
using namespace std;


int main(){
    int N, M;
    cin >> N >> M;

    int** arr = new int*[N]; // create an array of N(row) pointers
    for(int i = 0; i < N; i++){
        arr[i] = new int[M]; // allocate memory for each row
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j]; // Input elements
        }
    }


    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}