#include <iostream>
using namespace std;


// primary diagonal sum = summation arr[i][i] from i = 0 to N - 1;
int diagSum(int** arr, int N){
    int diagSum = 0;
    for(size_t i = 0; i < N; i++){
        diagSum += arr[i][i];
    }

    return diagSum;
}

// secondary diagonal sum = summation arr[i][N - 1 - i] from i = 0 to N - 1
// where N = number of rows
int secondaryDiagonalSum(int** arr, int N){
    int diagSum = 0;
    for(size_t i = 0; i < N; i++){
        diagSum += arr[i][N - 1 - i];
    }

    return diagSum;
}

void printArr(int** arr, int N, int M){
    for(size_t i = 0; i < N; i++){
        for(size_t j = 0; j < M; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void deleteArr(int** arr, int N){
    for(size_t i = 0; i < N; i++){
        delete[] arr[i];
    }

    delete[] arr;
}

int main(){
    int N;
    cin >> N;
    int M = N;

    int** arr = new int*[N];
    for(size_t i = 0; i < N; i++){
        arr[i] = new int[M];
    }

    for(size_t i = 0; i < N; i++){
        for(size_t j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }

    printArr(arr, N, M);
    cout << "Primary diagonal: " << diagSum(arr, N) << endl;
    cout << "Secondary diagonal: " << secondaryDiagonalSum(arr, N) << endl;

    deleteArr(arr, N);

    return 0;
}