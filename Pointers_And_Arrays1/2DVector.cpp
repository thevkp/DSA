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

int maxOnes(vector<vector<int>>& matrix){
    int maxOnes = 0;
    for(const auto& row : matrix){
        int countOnes = 0;
        for(int val : row){
            if(val == 1){
                countOnes++;
                maxOnes = countOnes > maxOnes ? countOnes : maxOnes;
            }
            if(val == 0)
                countOnes = 0;
        }
    }

    return maxOnes;
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


    vector<vector<int>> mat;
    int rows, columns, input;
    cin >> rows >> columns;
    for(int i = 0; i < 5; i++){
        vector<int> row;
        for(int j = 0; j < columns; j++){
            cin >> input;
            row.push_back(input);
        }
        mat.push_back(row);
    }

    cout << "Max ones: " << maxOnes(mat) << endl;
    return 0;
}
