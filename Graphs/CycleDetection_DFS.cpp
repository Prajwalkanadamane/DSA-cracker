#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{

    int V;
    list<int>* l;

    public:

    Graph(int V){
        this->V = V;
        l = new list<int> [V];

    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdjList(){
        for (int i=0; i<V; i++){
            cout << i << " : ";
            for (auto neigh : l[i]){
                cout << neigh << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    bool DFShelper(int u, int par, vector<bool>& vis){

        vis[u] = true;
        list<int> neighbor = l[u];

        for (auto v: neighbor){
            if (!vis[v]){
                if(DFShelper(v, u, vis)){
                    return true;
                }
            }
            else if(v != par){
                return true;
            }
        }
        return false;
    }

    bool DFS(){
        // int u = 0;
        vector<bool> vis(V, false);

        for (int i=0; i<V; i++){
            if (!vis[i]){
                if (DFShelper(i, -1, vis)){
                    return true;
                }
            }
        }
        return false;
    }

};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(0,3);
    g.addEdge(3,4);

    cout << endl << "Adjacency list: " << endl;
    g.printAdjList();

    cout << g.DFS() << endl;

    return 0;
}