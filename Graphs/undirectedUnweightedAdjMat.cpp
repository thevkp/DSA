#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjM;
    int nodes;

public:
    Graph(int nodes) {
        this->nodes = nodes;
        adjM.resize(this->nodes, vector<int>(this->nodes, 0));
    }

    void createGraph() {
        int edges;
        cin >> edges;

        for (int i = 0; i < edges; i++) {
            int u, v;
            cin >> u >> v;

            if (u >= 0 && u < nodes && v >= 0 && v < nodes) {
                adjM[u][v] = 1;
                adjM[v][u] = 1;
            } else {
                cout << "Invalid edge: (" << u << ", " << v << ")" << endl;
            }
        }
    }

    void printGraph() {
        for (const auto& row : adjM) {
            for (int col : row) {
                cout << col << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    system("cls");

    int numNodes;
    cin >> numNodes;

    Graph g(numNodes);

    g.createGraph();
    g.printGraph();

    return 0;
}

// 4
// 4
// 0 1
// 2 1
// 3 1
// 0 2
