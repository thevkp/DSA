#include <iostream>
using namespace std;


void transpose(int** arr, int N, int M, int** transMat){   
    for(size_t i = 0; i < N; i++){
        for(size_t j = 0; j < M; j++){
            transMat[j][i] = arr[i][j];
        }
    }
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
    int N, M;
    cin >> N >> M;

    int** arr = new int*[N]; // create an array row(N) pointers
    for(size_t i = 0; i < N; i++){
        arr[i] = new int[M];
    }

    for(size_t i = 0; i < N; i++){
        for(size_t j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }

    cout << "Original Array: " << endl;
    printArr(arr, N, M);
    cout << endl;

    int** transArr = new int*[M];
    for(size_t i = 0; i < M; i++){
        transArr[i] = new int[N];
    } 

    transpose(arr, N, M, transArr);
    cout << "Transposed Array: " << endl;
    printArr(transArr, M, N);


    // Free Memory
    deleteArr(arr, N);
    deleteArr(transArr, M);

    

    return 0;
}