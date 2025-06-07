#include <iostream>
#include <vector>
using namespace std;


int main(){
    system("cls");

    int n, edges;
    cin >> n >> edges;


    vector<vector<int>> adjL;

    while(edges--){
        vector<int> rows;
        int input;
        cin >> input;
        while(input != -1){
            rows.push_back(input);
            cin >> input;
        }
        adjL.push_back(rows);
    }


    // for(auto rows : adjL){
    //     for(auto nodes : rows){
    //         cout << nodes << " ";
    //     }
    //     cout << endl;
    // }

    for(int i = 0; i < n; i++){
        cout << i << " : ";
        for(int j = 0; j < adjL[i].size(); j++){
            cout << adjL[i][j] << " ";
        }
        cout << endl;
    }




    return 0;
}