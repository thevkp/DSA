#include <iostream>
#include <vector>
using namespace std;

class Graph{
    private:
        vector<vector<int>> adjM;
        int nodes;
    public:
        Graph(int nodes){
            this->nodes = nodes;
            adjM.resize(nodes, vector<int>(nodes, 0));
        }

        void createGraph(){
            int edges;
            cin >> edges;

            int u, v, w;
            while(edges--){
                cin >> u >> v >> w;
                adjM[u][v] = w;
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
};


int main(){
    system("cls");

    Graph g(4);

    g.createGraph();
    g.printGraph();


    return 0;
}

// 4 
// 0 1 7
// 2 1 5 
// 3 1 3
// 0 2 2