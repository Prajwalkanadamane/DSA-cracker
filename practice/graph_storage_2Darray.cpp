#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;


class graph{

    int V;
    list<int>* l;

    public:

    graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for (int i=0; i<V; i++){
            cout << i << " ";
            for (auto neigh : l[i]){
                cout << neigh << " ";
            }
            cout << endl;
        }
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

            for (auto neigh:l[u]){
                if (!vis[neigh]){
                    vis[neigh] = true;
                    Q.push(neigh);
                }
            }
        }
        cout << endl;

    }

    void DFSHelper(int u, vector<bool>& vis){

        cout << u << " ";
        vis[u] = true;
        for (auto v:l[u]){
            if (!vis[v]){
                DFSHelper(v, vis);
            }
        }

    }

    void DFS(){
        vector<bool> vis(V, false);
        int u = 0;

        DFSHelper(u, vis);
    }

    ~graph(){
        delete[] l;
    }
};

int main(){

    graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(0,4);

    // g.print();
    // g.BFS();
    g.DFS();
    return 0;
}