#include <iostream>
using namespace std;

void rotate90Degrees(int arr[][4], int rows){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < 4; j++){

        }
    }

}

int main(){
    int N, M;
    cin >> N >> M;

    // int arr[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    int** arr = new int*[N]; // creates a pointer of N(row) arrays;
    for(int i = 0; i < N; i++){
        arr[i] = new int[M]; // dynamically allocate memory for each row
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j]; // Input elements
        }
    }

    rotate90Degrees(arr, M);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << arr << endl;
    cout << arr[0] << endl;
    cout << arr[0][0] << endl;


    for(int i = 0; i < N; i++){
        delete arr[i];
    }
    delete arr;

    return 0;
}

// 4 4
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16