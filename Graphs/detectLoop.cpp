#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
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
    public:
        Graph(int nodes){
            this->nodes = nodes;
        }

        void createGraph(){
            int edges;
            cout << "Enter number of edges: ";
            cin >> edges;

            while(edges < 0){
                cout << "Invalid edges";
                cin >> edges;
            }

            int u, v;
            for(int i = 0; i < edges; i++){
                cin >> u >> v;

                if(selfLoop(u, v)){
                    cout << "Self Loop" << endl;
                    i--;
                    cin >> u >> v;
                    continue;
                }
                else if(invalidEdge(u, v)){
                    cout << "Invalid edge" << endl;
                    i--;
                    cin >> u >> v;
                    continue;
                }
                else if(adj[u].count(v)){
                    cout << "Duplicate edge" << endl;
                    i--;
                    cin >> u >> v;
                    continue;
                }

                adj[u].insert(v);
                adj[v].insert(u);
            }  
        }


        void printGraph(){
            for(const auto& pair : adj){
                cout << pair.first << " : ";
                for(const int& col : pair.second){
                    cout << col << " ";
                }
                cout << endl;
            }
        }

        unordered_map<int, unordered_set<int>> getAdj(){
            return adj;
        }
};

vector<int> bfs(const unordered_map<int, unordered_set<int>>& adj){
    int node;
    cout << "Enter start node: ";
    cin >> node;

    queue<int> q;
    unordered_map<int, bool> visited;
    vector<int> ans;

    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for(const int& neigh : adj.at(frontNode)){
            if(!visited[neigh]){
                q.push(neigh);
                visited[neigh] = true;
            }
        }
    }

    return ans;

}

void dfsUtil(int node, vector<int>& ans, vector<bool>& visited, const unordered_map<int, unordered_set<int>>& adj){
    ans.push_back(node);

    visited[node] = true;

    for(const int& neigh : adj.at(node)){
        if(!visited[neigh])
            dfsUtil(neigh, ans, visited, adj);
    }
}

vector<int> dfs(const unordered_map<int, unordered_set<int>>& adj){
    int start;
    cout << "Enter start node: ";
    cin >> start;

    vector<bool> visited(adj.size(), false);

    vector<int> ans;

    dfsUtil(start, ans, visited, adj);
    return ans;
}

int main(){
    system("cls");

    int nodes;
    cout << "Enter number of nodes: ";
    cin >> nodes;

    while(nodes < 0){
        cout << "Invalid number of nodes" << endl;
        cin >> nodes;
    }

    Graph g(nodes);
    g.createGraph();
    g.printGraph();

    vector<int> bfsTrav = bfs(g.getAdj());
    for(int& node : bfsTrav){
        cout << node << " ";
    }
    cout << endl;


    vector<int> dfsTrav = dfs(g.getAdj());
    for(int& node : dfsTrav){
        cout << node << " ";
    }

    return 0;
}




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


// 9
// 8
// 0 1 
// 1 2 
// 3 4 
// 4 5
// 5 6
// 5 7
// 6 7
// 7 8