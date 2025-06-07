#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;


class Graph{
    private:
        unordered_map<int, unordered_set<int>> adjL;

        void dfsUtil(int start, vector<int>& ans, vector<bool>& visited){
            ans.push_back(start);
            visited[start] = true;

            for(const auto& neigh : adjL[start]){
                if(!visited[neigh]){
                    dfsUtil(neigh, ans, visited);
                }
            }
        }
    public:
        void createGraph(){
            int edges;
            cout << "Edges: ";
            cin >> edges;

            int u, v;
            for(int i = 0; i < edges; i++){
                cin >> u >> v;

                if(u == v){
                    cout << "Self loop detected" << endl;
                    i--;
                    continue;
                }

                if(adjL[u].count(v) > 0 || adjL[v].count(u) > 0){
                    cout << "Duplicate Edge" << endl;
                    i--;
                    continue;
                }

                adjL[u].insert(v);
                adjL[v].insert(u);
            }
        }

        void printGraph(){
            for(const auto& lst : adjL){
                cout << lst.first << " : ";
                for(const int& edge : lst.second){
                    cout << edge << " ";
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

            while(node > adjL.size() - 1 || node < 0){
                cout << "Invalid Node" << endl;
                cin.clear();
                cin >> node;
            }

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
        cout << node << " ";
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



// 9 
// 0 1
// 2 3
// 3 1
// 1 6
// 4 6
// 6 2
// 1 8
// 6 7
// 8 2