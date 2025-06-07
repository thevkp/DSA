#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>> matrix){
    // int rows = matrix.size();
    // int cols = matrix[0].size();

    for(const auto& row : matrix){
        for(int val : row)
            cout << val << " ";
        cout << endl;
    }
    cout << endl;
}

int main(){
    system("cls");
    vector<vector<int>> matrix;
    vector<vector<int>> matrix1(5, vector<int>(5));

    // pushing in matrix 
    for(int i = 0; i < 5; i++){
        vector<int> row;
        for(int j = 0; j < 5; j++){
            row.push_back(i + j);
        }
        matrix.push_back(row);
    }

    // updating elements in matrix1 // it won't double the size, when filled completely
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            matrix1[i][j] = i + j;
        }
    }

    printMatrix(matrix);
    printMatrix(matrix1);

    cout << matrix.size() << " " << matrix1.size() << endl;
    cout << matrix[0].size() << " " << matrix1[0].size() << endl;
    cout << matrix.capacity() << " " << matrix1.capacity() << endl;
    return 0;
}
