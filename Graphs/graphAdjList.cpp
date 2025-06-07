#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
using namespace std;


class Graph{
    private:    
        unordered_map<int, list<int>> adjL;
        int nodes;

        void dfsUtil(int start, vector<int>& ans, vector<bool>& visited){
            ans.push_back(start);

            visited[start] = true;

            for(auto& it : adjL){
                if(!visited[it.first])
                    dfsUtil(it.first, ans, visited);
            }
        }
    public:
        Graph(int nodes){
            this->nodes = nodes;
        }


        void createGraph(){
            int edges;
            cout << "No. of edges: ";
            cin >> edges;

            int u, v;
            for(int i = 0; i < edges; i++){
                cin >> u >> v;
                adjL[u].push_back(v);
                adjL[v].push_back(u);
            }
        }

        void printGraph(){
            for(const auto& lst : adjL){
                cout << lst.first << " : ";
                for(const auto& it : lst.second){
                    cout << it << " ";
                }
                cout << endl;
            }
        }

        vector<int> dfs(int start){
            vector<bool> visited(nodes, false);
            vector<int> ans;

            dfsUtil(start, ans, visited);
            return ans;
        }
};




int main(){
    system("cls");

    int nodes;
    cout << "No. of nodes: ";
    cin >> nodes;

    Graph g(nodes);

    g.createGraph();
    g.printGraph();

    int start;
    cout << "Enter start node for traversal: ";
    cin >> start;
    vector<int> dfsTrav = g.dfs(start);
    for(const int& node : dfsTrav){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}


// 5
// 6
// 0 1  
// 1 2 
// 2 3 
// 3 1
// 3 4
// 0 4