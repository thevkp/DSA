#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph{
    private:
        unordered_map<int, vector<int>> adj;
        int nodes;

        void dfsUtil(int start, vector<int>& ans, vector<bool>& visited){
            ans.push_back(start);

            visited[start] = true;

            for(auto neigh : adj[start]){
                if(!visited[neigh]){
                    dfsUtil(neigh, ans, visited);
                }
            }
        }
    public:
        Graph(int nodes){
            this->nodes = nodes;
        }

        void createGraph(){
            int edges;
            cin >> edges;

            int u, v;
            for(int i = 0; i < edges; i++){
                cin >> u >> v;
                // adj[u].insert(v);
                // adj[v].insert(u);
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        void printGraph(){
            for(const auto& pair : adj){
                cout << pair.first << ": ";
                for(const int& val : pair.second){
                    cout << val << " ";
                }
                cout << "\n";
            }
        }

        vector<int> dfs(){
            vector<int> ans;
            vector<bool> visited(nodes, false);


            dfsUtil(0, ans, visited);
            return ans;
        }
};


int main(){
    system("cls");

    Graph g(5);

    g.createGraph();
    g.printGraph();


    vector<int> dfsTrav = g.dfs();
    for(int& num : dfsTrav){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}