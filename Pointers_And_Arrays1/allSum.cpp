#include <iostream>
#include <utility>
using namespace std;

void rowSum(int arr[][4], int row, int col){
    for(int i = 0; i < row; i++){
        int sum = 0;
        for(int j = 0; j < col; j++){
            sum += arr[i][j];
        }
        cout << "Sum of row " << i << ": " << sum << endl;
    }
    cout << endl;
}

void colSum(int arr[][4], int row, int col){
    for(int i = 0; i < col; i++){
        int sum = 0;
        for(int j = 0; j < row; j++){
            sum += arr[j][i];
        }
        cout << "Sum of col " << i << ": " << sum << endl;
    }
    cout << endl;
}

void diagonalSum(int arr[][4], int row, int col){
    int sum = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(i == j)
                sum += arr[i][j];
        }
    }
    cout << "Sum of diagonal elements: " << sum << endl;
}

pair<int, int> largestRowSum(int arr[][4], int row, int col){
    int largest = arr[0][0];
    int rowIndex = -1;
    for(int i = 0; i < row; i++){
        int sum = 0;
        for(int j = 0; j < col; j++){
            sum += arr[i][j];
            if(sum > largest){
                largest = sum;
                rowIndex = i;
            }
        }
    }
    return make_pair(largest, rowIndex);
}

int largestColSum(int arr[][4], int row, int col){
    int largest = arr[0][0];
    for(int i = 0; i < col; i++){
        int sum = 0;
        for(int j = 0; j < row; j++){
            sum += arr[j][i];
            if(largest < sum)
                largest = sum;
        }
    }
    return largest;
}

int main(){
    system("cls");
    int arr[4][4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            arr[i][j] = i + j;
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    
    rowSum(arr, 4, 4);
    colSum(arr, 4, 4);
    diagonalSum(arr, 4, 4);
    
    pair<int, int> rowAndIndex = largestRowSum(arr, 4, 4);
    cout << "Largest row sum: " << rowAndIndex.first << endl;
    cout << "Row with largest sum: " << rowAndIndex.second << endl;
    cout << largestColSum(arr, 4, 4) << endl;

    return 0;
}