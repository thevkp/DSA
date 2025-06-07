#include <iostream>
#include <vector>
using namespace std;


int main(){
    system("cls");
    int n;
    cin >> n;
    vector<vector<int>> adjM(n, vector<int>(n, 0));

    int edges;
    cin >> edges;

    while(edges--){
        int u, v, w;
        cin >> u >> v >> w;
        adjM[u][v] = w;
    }

    for(auto rows : adjM){
        for(int cols : rows){
            cout << cols << " ";
        }
        cout << endl;
    }

    return 0;
}