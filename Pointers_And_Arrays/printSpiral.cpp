#include <iostream>
#include <vector>
using namespace std;

vector<int> spiral(vector<vector<int>> matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int count = 0;
    int total = rows * cols;

    // Initializing indexing variables
    int startRow = 0;
    int startCol = 0;
    int endRow = rows - 1;
    int endCol = cols - 1;

    vector<int> ans; // No need to preallocate size

    while(count < total) {
        // Print starting row
        for(int i = startCol; i <= endCol && count < total; i++) {
            ans.push_back(matrix[startRow][i]);
            count++;
        }
        startRow++;

        // Print end column
        for(int i = startRow; i <= endRow && count < total; i++) {
            ans.push_back(matrix[i][endCol]);
            count++;
        }
        endCol--;

        // Print end row
        for(int i = endCol; i >= startCol && count < total; i--) {
            ans.push_back(matrix[endRow][i]);
            count++;
        }
        endRow--;

        // Print start column
        for(int i = endRow; i >= startRow && count < total; i--) {
            ans.push_back(matrix[i][startCol]);
            count++;
        }
        startCol++;
    }

    return ans;
}

int main(){
    system("cls");
    vector<vector<int>> matrix(5, vector<int>(5));

    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++)
            matrix[i][j] = i + j;
    }

    for(const auto& row : matrix){
        for(int val : row){
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;

    vector<int> sprl = spiral(matrix);
    for(int val : sprl){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}