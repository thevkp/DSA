#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;


class Graph{
    private:
        unordered_map<int, list<int>> adjL;
        void dfsUtil(int node, vector<int>& ans, vector<bool>& visited){
            ans.push_back(node);
            visited[node] = true;

            // for(const auto& curr : adjL[node]){
            //     if(!visited[curr])
            //         dfsUtil(curr, ans, visited);
            // }

            for (auto& neigh : adjL[node]) {
                if (!visited[neigh])
                    dfsUtil(neigh, ans, visited);
            }

            // for(int i = 0; i < adjL.size(); i++){
            //     if(!visited[i])
            //         dfsUtil(i, ans, visited);
            // }
        }
    public:
        void createGraph(){
            int edges;
            cin >> edges;

            int u, v;
            for(int i = 0; i < edges; i++){
                cin >> u >> v;

                if(u == v) {
                    cout << "Self-loop detected at " << u << ". Ignoring...\n";
                    continue;
                }
                
                if(find(adjL[u].begin(), adjL[u].end(), v) != adjL[u].end()) {
                    cout << "Edge (" << u << ", " << v << ") is a duplicate. Ignoring...\n";
                    continue;
                }

                adjL[u].push_back(v);
                adjL[v].push_back(u);
            }
        }

        void printGraph(){
            for(const auto& lst : adjL){
                cout << lst.first << " : ";
                for(const int& link : lst.second){
                    cout << link << " ";
                }
                cout << endl;
            }
        }

        vector<int> dfs(){
            vector<int> ans;
            vector<bool> visited(adjL.size(), false);

            int node;
            cout << "Starting node: ";
            cin >> node;

            dfsUtil(node, ans, visited);
            return ans;
        }
};





int main(){
    system("cls");


    Graph g;

    g.createGraph();
    g.printGraph();

    vector<int> dfsTrav = g.dfs();
    for(const int& node : dfsTrav){
        cout <<  node << " ";
    }
    cout << endl;



    return 0;
}

 
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