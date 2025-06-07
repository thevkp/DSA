#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph{
    private:
        unordered_map<int, unordered_set<int>> adj;
        int nodes;

        bool selfLoop(int u, int v){
            return u == v;
        }

        bool invalidEdge(int u, int v){
            return u >= nodes || v >= nodes || u < 0 || v < 0;
        }

        void dfsUtil(int start, vector<int>& ans, vector<bool>& visited){
            ans.push_back(start);
            visited[start] = true;

            for(const int& neigh : adj[start]){
                if(!visited[neigh])
                    dfsUtil(neigh, ans, visited);
            }
        }
    public:
        Graph(int nodes){
            this->nodes = nodes;
        }

        void createGraph(){
            int edges;
            cout << "Enter the number of edges: ";
            cin >> edges;

            int u, v;
            for(int i = 0; i < edges; i++){
                cin >> u >> v;

                if(selfLoop(u, v)){
                    cout << "Self loop" << endl;
                    i--;
                    continue;
                }
                else if(invalidEdge(u, v)){
                    cout << "Invalid Edge" << endl;
                    i--;
                    continue;
                }
                else if(adj[u].count(v)){
                    cout << "Duplicate edge" << endl;
                    i--;
                    continue;
                }

                adj[u].insert(v);
                adj[v].insert(u);
            }
        }
        void printGraph(){
            for(const auto& pair : adj){
                cout << pair.first << " : ";
                for(const int& node : pair.second){
                    cout << node << " ";
                }
                cout << endl;
            }

        }

        unordered_map<int, unordered_set<int>> getAdj(){
            return adj;
        }

        vector<int> bfs(){
            vector<int> res;
            queue<int> q;
            unordered_map<int, bool> visited;

            int node;
            cout << "Enter start node: ";
            cin >> node;
            q.push(node);

            visited[node] = true;

            while(!q.empty()){
                int frontNode = q.front();
                q.pop();

                res.push_back(frontNode);

                for(const int& neigh : adj[frontNode]){
                    if(!visited[neigh]){
                        q.push(neigh);
                        visited[neigh] = true;
                    }
                }
            }
            return res;
        }

        vector<int> dfs(){
            vector<int> res;
            vector<bool> visited(nodes, false);

            int node;
            cout << "Enter start node: ";
            cin >> node;

            dfsUtil(node, res, visited);

            return res;
        }
};

void dfs(int start, unordered_map<int, bool>& visited, unordered_map<int, unordered_set<int>>& adj){
    visited[start] = true;

    for(const int& neigh : adj[start]){
        if(!visited[neigh])
            dfs(neigh, visited, adj);
    }
}


// int countConnectedComponents(unordered_map<int, unordered_set<int>>& adj){
//     unordered_map<int, bool> visited;

//     int count = 0;

//     for(const auto& pair : adj){
//         int node = pair.first;
//         cout << "Traversing: " << node << endl;
//         if(!visited[node]){
//             count += 1;
//             dfs(node, visited, adj);
//         }
//     }

//     return count;
// }

int countConnectedComponents(int nodes, unordered_map<int, unordered_set<int>>& adj) {
    unordered_map<int, bool> visited;
    int count = 0;

    for (int node = 0; node < nodes; node++) {  
        if (!visited[node]) { 
            count++;
            dfs(node, visited, adj);  
        }
    }

    return count;
}

void printNodes(const unordered_map<int, unordered_set<int>>& adj){
    for(const auto& pair : adj){
        cout << pair.first << " ";
    }
    cout << endl;
}



int main(){
    system("cls");

    int nodes;
    cout << "Enter number of nodes: ";
    cin >> nodes;


    Graph g(nodes);
    g.createGraph();
    g.printGraph();

    vector<int> bfsTrav = g.bfs();
    cout << "BFS: ";
    for(const int& node : bfsTrav){
        cout << node << " ";
    }
    cout << endl;


    vector<int> dfsTrav = g.dfs();
    cout << "DFS: ";
    for(const int& node : dfsTrav){
        cout << node << " ";
    }
    cout << endl;


    cout << "All nodes: ";
    printNodes(g.getAdj());

    unordered_map<int, unordered_set<int>> adj = g.getAdj();
    cout << countConnectedComponents(nodes, adj) << endl;

    return 0;
}

// 5
// 4
// 0 1 
// 0 2
// 1 3
// 1 4

// 5
// 4
// 0 3
// 3 1
// 1 2
// 1 4

// 6
// 3
// 0 1
// 1 2
// 3 4