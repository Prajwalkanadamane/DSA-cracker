#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
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

    void dfs(int curr, vector<bool>& vis, stack<int>& s){

        vis[curr] = true;

        for (auto neigh : l[curr]){
            if (!vis[neigh]){
                dfs(neigh, vis, s);
            }

        }
        s.push(curr);
    }

    void topoSort(){
        vector<bool> vis(V, false);
        stack<int> s;

        for (int i=0; i<V; i++){
            if (!vis[i]){
                dfs(i, vis, s);
            }
        }

        while(!s.empty()){
            int top = s.top();
            cout << top << " ";
            s.pop();
        }
    }
};

int main(){
    Graph g(6);

    g.addEdge(5,0);
    g.addEdge(4,0);
    g.addEdge(5,2);
    g.addEdge(4,1);
    g.addEdge(2,3);
    g.addEdge(3,1);

    cout << "Topological Sort: ";
    g.topoSort();

    return 0;
}