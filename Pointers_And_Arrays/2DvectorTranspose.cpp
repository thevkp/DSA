#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& mat){
    int rows = mat.size();
    int cols = mat[0].size();

    vector<vector<int>> transMatrix(cols, vector<int>(rows));

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            transMatrix[j][i] = mat[i][j];
        }
    }

    return transMatrix;
}


int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> matrix;

    for(int i = 0; i < N; i++){
        vector<int> row(M);
        for(int j = 0; j < M; j++){
            cin >> row[j];
        }
        matrix.push_back(row);
    }

    vector<vector<int>> transMatrix = transpose(matrix);
    for(auto& row : transMatrix){
        for(int& num : row){
            cout << num << " ";
        }
        cout << endl;
    }

    


    return 0;
}