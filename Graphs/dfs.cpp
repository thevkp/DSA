#include <iostream>
#include <vector>
using namespace std;


class Graph{
    private:
        vector<vector<int>> adjM;
        int nodes;

        void DFS(int start, vector<bool>& visited){ 
            cout << start << " ";

            visited[start] = true;
            for(int i = 0; i < nodes; i++){
                if(adjM[start][i] == 1 && !visited[i])
                    DFS(i, visited);
            }
        }
    public:
        Graph(int nodes){
            this->nodes = nodes;
            adjM.resize(nodes, vector<int>(nodes, 0));
        }

        void createGraph(){
            int edges;
            cin >> edges;

            int u, v;
            while(edges--){
                cin >> u >> v;

                if(u >= nodes || v >= nodes || u < 0 || v < 0){
                    cout << "Invalid edge" << endl;
                    edges++;
                    continue;
                }

                adjM[u][v] = 1;
                adjM[v][u] = 1;
            }
        }

        void printGraph(){
            for(const auto& rows : adjM){
                for(const int& col : rows){
                    cout << col << " ";
                }
                cout << endl;
            }
        }


        void DFS_Traversal(int start){
            vector<bool> visited(nodes, false);

            DFS(start, visited);
            cout << endl;
        }
};


int main(){
    system("cls");

    int nodes;
    cin >> nodes;

    Graph g(nodes);

    g.createGraph();
    g.printGraph();
    cout << endl;
    g.DFS_Traversal(0);


    return 0;
}

// 4 
// 0 1
// 2 1
// 3 1
// 0 2

// 5
// 4
// 0 1
// 0 6
// 0 4
// 1 2
// 2 3 

// 5
// 5
// 0 1
// 0 2
// 1 2
// 2 3
// 2 4

// 5
// 4
// 0 1 
// 0 2
// 1 3
// 1 4