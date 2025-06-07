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

                if(u >= nodes || v >= nodes || u < 0 || v < 0){
                    cout << "Invalid edge! Nodes should be between 0 and " << nodes - 1 << ".\n";
                    edges++;
                    continue;
                }

                adjM[u][v] = w;
            }
        }

        void printGraph(){
            for(const auto& rows : adjM){
                for(const auto& col : rows){
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