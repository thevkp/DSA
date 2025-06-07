#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
template <typename T>


class Graph{
    private:
        unordered_map<T, list<T>> adj;
    public:
        void createGraph(T u, T v, bool direction){
            adj[u].push_back(v);
            if(direction == 0){
                adj[v].push_back(u);
            }
        }

        void printGraph(){
            for(auto i : adj){
                cout << i.first << "->";
                for(auto j : i.second){
                    cout << j << ", ";
                }
                cout << endl;
            }
        }
};


int main(){
    system("cls");

    Graph<int> g;

    int u, v;
    cin >> u >> v;

    while(u != -1 && v != -1){
        g.createGraph(u, v, 0);
        cin >> u >> v;
    }

    g.printGraph();



    return 0;
}