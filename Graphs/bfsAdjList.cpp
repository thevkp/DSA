#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Graph {
private:
    unordered_map<int, unordered_set<int>> adjL;
    int nodes;

    bool selfLoop(int u, int v) {
        return u == v;
    }

    bool invalidEdge(int u, int v) {
        return u >= nodes || v >= nodes || u < 0 || v < 0;
    }

    void bfsUtil(int node, unordered_map<int, bool>& visited){
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            cout << frontNode << " ";

            for(const auto& neigh : adjL[frontNode]){
                if(!visited[neigh]){
                    q.push(neigh);
                    visited[neigh] = true;
                }
            }
        }
    }

public:
    void createGraph() {
        int edges;
        cout << "Enter the number of nodes: ";
        cin >> nodes;
        cout << "Enter the number of edges: ";
        cin >> edges;

        int u, v;
        for (int i = 0; i < edges; i++) {
            cin >> u >> v;

            while (selfLoop(u, v) || invalidEdge(u, v) || adjL[u].count(v)) {
                if (selfLoop(u, v)) {
                    cout << "Self loop detected! Enter a valid edge: ";
                } 
                else if (invalidEdge(u, v)) {
                    cout << "Invalid edge! Nodes must be in range [0, " << nodes - 1 << "]. Enter again: ";
                } 
                else if (adjL[u].count(v)) {
                    cout << "Duplicate edge! Enter a new edge: ";
                }
                cin >> u >> v;
            }

            adjL[u].insert(v);
            adjL[v].insert(u);
        }
    }

    void printGraph() {
        for (const auto& pair : adjL) {
            cout << pair.first << " : ";
            for (int neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void bfs(){
        unordered_map<int, bool> visited;
        int start;
        cout << "Enter start node: ";
        cin >> start;

        bfsUtil(start, visited);
    }
};

int main() {
    system("cls");

    Graph g;
    g.createGraph();
    g.printGraph();
    g.bfs();

    return 0;
}


// 9
// 9
// 0 1
// 2 3
// 3 1
// 1 6
// 4 6
// 1 6
// 6 2
// 3 1
// 1 8


// 5
// 4
// 0 3
// 3 1
// 1 2
// 1 4