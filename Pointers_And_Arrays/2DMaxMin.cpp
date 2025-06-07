#include <iostream>
using namespace std;


int max(int** arr, int N, int M){
    int max = arr[0][0];
    for(size_t i = 0; i < N; i++){
        for(size_t j = 0; j < M; j++)
        if(max < arr[i][j])
            max = arr[i][j];
    }

    return max;
}

int min(int** arr, int N, int M){
    int min = arr[0][0];
    for(size_t i = 0; i < N; i++)
    for(size_t j = 0; j < M; j++){
        if(min > arr[i][j])
            min = arr[i][j];
    }

    return min;
}

void deleteArr(int** arr, int N){
    for(size_t i = 0; i < N; i++){
        delete[] arr[i];
    }
    delete[] arr;
}

int main(){ 
    int N, M;
    cin >> N >> M;

    int** arr = new int*[N];
    for(size_t i = 0; i < N; i++){
        arr[i] = new int[M];
    }

    for(size_t i = 0; i < N; i++){
        for(size_t j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }

    cout << "Max: " << max(arr, N, M) << endl;
    cout << "Min: " << min(arr, N, M) << endl;

    deleteArr(arr, N);

    return 0;
}