#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
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

        void bfsUtil(int node, unordered_map<int, bool>& visited){
            queue<int> q;
            q.push(node);
            visited[node] = true;

            while(!q.empty()){
                int frontNode = q.front();
                q.pop();

                cout << frontNode << " ";

                for(auto& neigh : adjS[frontNode]){
                    if(!visited[neigh]){
                        q.push(neigh);
                        visited[neigh] = true;
                    }
                }
            }
        }
    public:
        Graph(int nodes){
            this->nodes = nodes;
        }

        void createGraph(){
            int edges;
            cout << "Enter number of edges: ";
            cin >> edges;

            int u, v;
            for(int i = 0; i < edges; i++){
                cin >> u >> v;

                while(selfLoop(u, v) || invalidEdge(u, v) || adjS[u].count(v)){
                    if(selfLoop(u, v)){
                        cout << "Self loop" << endl;
                        i--;
                    }
                    else if(invalidEdge(u, v)){
                        cout << "Invalid edge" << endl;
                        i--;
                    }
                    else if(adjS[u].count(v)){
                        cout << "Duplicate Edge" << endl;
                        i--;
                    }
                }

                adjS[u].insert(v);
                adjS[v].insert(u);
            }
        }

        void bfs(){
            unordered_map<int, bool> visited;
            int node;
            cout << "Start node: ";
            cin >> node;

            bfsUtil(node, visited);
            cout << endl;
        }

        vector<int> findIndeg(){
            vector<int> indeg(nodes + 1, 0);

            for(auto v : adjS){
                for(int neighbor : v.second){
                    indeg[neighbor]++;
                }
            }

            for(int i = 0; i < nodes; i++){
                cout << i << " : " << indeg[i] << endl;
            }
        }

};





int main(){
    system("cls");

    int nodes;
    cout << "Enter number of nodes: ";
    cin >> nodes;


    Graph g(nodes);
    g.createGraph();
    g.bfs();
    g.findIndeg();

    return 0;
}


// 5
// 4
// 0 3
// 3 1
// 1 2
// 1 4