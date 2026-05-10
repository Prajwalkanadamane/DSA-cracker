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

    bool CycleDectUndir_BFS(int src, vector<bool>& vis){        
        queue<pair<int, int>> q;

        q.push({src, -1});
        vis[src] = true;

        while(!q.empty()){

            int Curr_src = q.front().first;
            int Curr_par = q.front().second;

            q.pop();

            for (auto v : l[Curr_src]){
                if (!vis[v]){
                    q.push({v, Curr_src});
                    vis[v] = true;
                }else if (v != Curr_par){
                    return true;
                }
            }
        }
        return false;
    }

    bool CycleDectUndir_BFS_main(){

        vector<bool> vis(V, false);

        for (int i=0; i<V; i++){
            if (!vis[i]){
                if(CycleDectUndir_BFS(i, vis)){
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
    // g.addEdge(1,2);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(3,4);

    cout << endl << "Adjacency list: " << endl;
    g.printAdjList();

    cout << g.CycleDectUndir_BFS_main() << endl;

    return 0;
}