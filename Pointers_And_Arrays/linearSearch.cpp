#include <iostream>
#include <utility>
using namespace std;

pair<int, int> search(int arr[][4], int target, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(arr[i][j] == target)
                return pair<i,j>;
        }
    }
}

int main(){


    return 0;
}