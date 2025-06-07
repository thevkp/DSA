#include <iostream>
#include <vector>
using namespace std;


class Graph{
    private:    
        vector<vector<int>> adj;
        int nodes;
    public:
        Graph(int nodes){
            this->nodes = nodes;
            adj.resize(nodes, vector<int>(nodes, 0));
        }

        void createGraph(){
            int edges;
            cin >> edges;

            int u, v;
            while(edges--){
                cin >> u >> v;

                if(u >= nodes || v >= nodes || u < 0 || v < 0){
                    cout << "Invalid input" << "\n";
                    edges++;
                    continue;
                }

                adj[u][v] = 1;
                adj[v][u] = 1;
            }
        }

        void printGraph(){
            for(const auto& rows : adj){
                for(const int& col : rows){
                    cout << col << " ";
                }
                cout << endl;
            }
        }
};



int main(){
    system("cls");

    int nodes;
    cin >> nodes;

    Graph g(nodes);

    g.createGraph();
    g.printGraph();


    return 0;
}