#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;


class Graph{
    private:
        unordered_map<int, list<int>> adj;
    public:
        void addEdge(int u, int v, bool direction){
            adj[u].push_back(v);

            if(!direction)
                adj[v].push_back(u);
        }

        void printGraph(){
            for(auto i : adj){
                cout << i.first << "->";
                for(auto j : i.second){
                    cout << j << ",";
                }
                cout << endl;
            }
        }

};

int main(){
    system("cls");


    Graph g;

    int u, v;
    cin >> u >> v;
    bool direction;
    cin >> direction;

    // bool flag = 1;
    while(v != -1){
        g.addEdge(u, v, direction);
        cin >> u >> v;
        cin >> direction;
    }


    g.printGraph();



    return 0;
}