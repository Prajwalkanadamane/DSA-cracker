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

    void BFS(){

        queue<int> Q;
        vector<bool> vis(V, false);

        Q.push(0);
        vis[0] = true;

        while(!Q.empty()){

            int u = Q.front();
            Q.pop();

            cout << u << " ";
            
            for (auto v : l[u]){
                if(!vis[v]){
                    vis[v] = true;
                    Q.push(v);
                }
            }

        }
        cout << endl;

    }

    void DFShelper(int u, vector<bool>& vis){

        cout << u << " ";
        vis[u] = true;

        for (auto v: l[u]){
            if (!vis[v]){
                DFShelper(v, vis);
            }
        }
    }

    void DFS(){
        int u = 0;
        vector<bool> vis(V, false);

        DFShelper(u, vis);
    }

};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    // g.addEdge(2,4);

    cout << endl << "Adjacency list: " << endl;
    g.printAdjList();

    cout << "BFS traversal: ";
    g.BFS();

    cout << "DFS traversal: ";
    g.DFS();

    return 0;
}