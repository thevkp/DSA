#include <iostream>
using namespace std;

void printWave(int arr[][4], int row, int col){
    for(int i = 0; i < col; i++){
        // even columns, top to bottom
        if(i % 2 == 0){
            for(int j = 0; j < row; j++){
                cout << arr[j][i] << " ";
            }
        }
        else{
            for(int j = row - 1; j >= 0; j--){
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    system("cls");
    int arr[4][4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++)
            arr[i][j] = i + j;
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    printWave(arr, 4, 4);

    return 0;
}