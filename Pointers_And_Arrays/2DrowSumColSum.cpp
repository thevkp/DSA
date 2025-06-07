#include <iostream>
using namespace std;

void eachRowSum(int** arr, int N, int M, int* rowSums){
    for(int i = 0; i < N; i++){
        rowSums[i] = 0;
        for(int j = 0; j < M; j++){
            rowSums[i] += arr[i][j];
        }
    }
}

int firstRowSum(int** arr, int N, int M){
    int sum = 0;
    for(int i = 0; i < 1; i++){
        for(int j = 0; j < M; j++){
            sum += arr[i][j];
        }
    }

    return sum;
}

int allElementSum(int** arr, int N, int M){
    int sum = 0;
    for(size_t i = 0; i < N; i++){
        for(size_t j = 0; j < M; j++){
            sum += arr[i][j];
        }
    }

    return sum;
}


void eachColSum(int** arr, int N, int M, int* colSums){
    int sum = 0;
    for(int j = 0; j < M; j++){
        for(int i = 0; i < N; i++){
            sum += arr[i][j];
        }
        colSums[j] = sum;
        sum = 0;
    }
}

int main(){
    int N, M;
    cin >> N >> M;

    int** arr = new int*[N];
    for(int i = 0; i < N; i++){
        arr[i] = new int[M];
    }


    for(size_t i = 0; i < N; i++){
        for(size_t j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }


    cout << allElementSum(arr, N, M) << endl;
    cout << firstRowSum(arr, N, M) << endl;

    int* rowSums = new int[N];
    eachRowSum(arr, N, M, rowSums);
    cout << "Individual sum of each row: " << endl;
    for(size_t i = 0; i < N; i++){
        cout << rowSums[i] << " ";
    }
    cout << endl;


    int* colSums = new int[M];
    eachColSum(arr, N, M, colSums);
    cout << "Individual sum of each column: " << endl;
    for(size_t i = 0; i < M; i++){
        cout << colSums[i] << " ";
    }
    cout << endl;



    for(size_t i = 0; i < N; i++){
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}