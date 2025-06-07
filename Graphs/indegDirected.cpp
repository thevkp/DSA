#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;


class Graph{
    private:
        unordered_map<int, unordered_set<int>> adjS;
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
            for(const int& neight : adjS[start]){
                if(!visited[neight])
                    dfsUtil(neight, ans, visited);
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

            int u , v;
            for(int i = 0; i < edges; i++){
                cin >> u >> v;

                if(selfLoop(u, v)){
                    cout << "Self Loop" << endl;
                    i--;
                    continue;
                }
                else if(invalidEdge(u, v)){
                    cout << "Inavalid edge" << endl;
                    i--;
                    cin >> u >> v;
                }
                else if(adjS[u].count(v) || adjS[v].count(u)){
                    cout << "Duplicate edge" << endl;
                    i--;
                    continue;
                }

                adjS[u].insert(v);
            }
        }

        void printGraph(){
            for(const auto& s : adjS){
                cout << s.first << " : ";
                for(const int& val : s.second){
                    cout << val << " ";
                }
                cout << endl;
            }
        }

        vector<int> bfs(){
            queue<int> q;
            unordered_map<int, bool> visited;
            vector<int> ans;

            int node;
            cout << "Start node: ";
            cin >> node;

            while(node < 0 || node >= nodes){
                cout << "Invalid start node! Must be between 0 and " << nodes - 1 << "." << endl;
                cin >> node;
            }

            q.push(node);
            visited[node] = true;
            while(!q.empty()){
                int frontNode = q.front();
                q.pop();
                ans.push_back(frontNode);

                for(auto& neigh : adjS[frontNode]){
                    if(!visited[neigh]){
                        q.push(neigh);
                        visited[neigh] = true;
                    }
                }
            }

            return ans;
        }
        
        vector<int> dfs(){
            vector<bool> visited(nodes, false);
            vector<int> ans;

            int node;
            cout << "Start node: ";
            cin >> node;

            while(node < 0 || node >= nodes){
                cout << "Invalid start node! Must be between 0 and " << nodes - 1 << "." << endl;
                cin >> node;
            }

            dfsUtil(node, ans, visited);
            return ans;

        }
};




int main(){
    system("cls");

    int nodes;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    Graph g(nodes);
    g.createGraph();
    g.printGraph();

    vector<int> bfsTrav = g.bfs();
    for(const int& node : bfsTrav){
        cout << node << " ";
    }
    cout << endl;

    vector<int> dfsTrav = g.dfs();
    for(const int& node : dfsTrav){
        cout << node << " ";
    }
    cout << endl;


    return 0;
}


// 5
// 8
// 0 3
// 3 2
// 3 1
// 1 0
// 2 4
// 4 1
// 1 2
// 2 0