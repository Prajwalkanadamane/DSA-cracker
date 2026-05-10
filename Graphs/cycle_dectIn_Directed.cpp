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
        // l[v].push_back(u);
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

    bool CycleDectdir_DFS(int src, vector<bool>& vis, vector<bool>& RecPath){        
        
        vis[src] = true;
        RecPath[src] = true;

        for (auto v : l[src]){
            if (!vis[v]){
                if (CycleDectdir_DFS(v, vis, RecPath)){
                    return true;
                }
            }else if(RecPath[v]){
                return true;
            }
        }
        RecPath[src] = false;
        return false;
    }

    bool CycleDectdir_DFS_main(){

        vector<bool> vis(V, false);
        vector<bool> RecPath(V, false);

        for (int i=0; i<V; i++){
            if (!vis[i]){
                if(CycleDectdir_DFS(i, vis,RecPath)){
                    return true;
                }
            }
        }
        return false;
    }

};

int main(){
    Graph g(5);

    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(3,4);

    cout << endl << "Adjacency list: " << endl;
    g.printAdjList();

    cout << g.CycleDectdir_DFS_main() << endl;

    return 0;
}