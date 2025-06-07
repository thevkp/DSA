#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


class Graph{
    private:
        vector<vector<int>> adjM;
        int nodes;

        void bfsUtil(int node, unordered_map<int, bool>& visited){
            queue<int> q;
            q.push(node);

            while(!q.empty()){
                int frontNode = q.front();
                q.pop();

                cout << frontNode << " ";
                visited[node] = true;

                for(int i = 0; i < adjM.size(); i++){
                    if(adjM[frontNode][i] == 1 && !visited[i]){
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
    public:
        Graph(int nodes){
            this->nodes = nodes;
            adjM.resize(nodes, vector<int>(nodes, 0));
        }

        void createGraph(){
            int edges;
            cout << "Number of edges: ";
            cin >> edges;

            int u, v;
            for(int i = 0; i < edges; i++){
                cin >> u >> v;

                while(u == v){
                    cout << "Self Loop:" << endl;
                    cin.clear();
                    i++;
                    cin >> u >> v;
                }

                while(u >= nodes || v >= nodes || u < 0 || v < 0){
                    cout << "Invalid Edge" << endl;
                    cin.clear();
                    i++;
                    cin >> u >> v;
                }

                while(adjM[u][v] == 1 || adjM[v][u] == 1){
                    cout << "Duplicate Edge Detected" << endl;
                    cin.clear();
                    i++;
                    cin >> u >> v;
                }

                adjM[u][v] = 1;
                adjM[v][u] = 1;
            }
        }

        void printGraph(){
            for(const auto& row : adjM){
                for(const int& col : row){
                    cout << col << " ";
                }
                cout << endl;
            }
        }

        void bfs(){
            unordered_map<int, bool> visited;

            int node;
            cout << "Enter start node: ";
            cin >> node;

            bfsUtil(node, visited);
        }
};

int main(){
    system("cls");

    int nodes;
    cout << "Number of Nodes: ";
    cin >> nodes;


    Graph g(nodes);

    g.createGraph();
    g.printGraph();

    g.bfs();
    cout << endl;





    return 0;
}



// 4
// 4
// 0 1
// 0 3
// 1 2
// 2 3

// 5
// 4
// 0 3
// 3 1
// 1 2
// 1 4


// 7
// 8
// 0 1
// 0 2
// 1 3
// 1 4
// 2 5
// 2 6
// 3 4
// 5 6
