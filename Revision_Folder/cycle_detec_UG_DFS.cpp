#include<iostream>
#include<vector>
#include<list>
using namespace std;

class graph{

    int V;
    list<int>* l; // l is a pointer of the datatype list<int>

    public:
    graph(int V){
        this->V = V;
        l = new list<int>[V]; // l pointer is locating a dynamic memory location where list<int> of size is V is present
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for (int i=0; i<V; i++){
            cout << i << ": ";
            for (auto neigh:l[i]){
                cout << neigh << " ";
            }
            cout << endl;
        }

    }

    bool cycle_dict_helper(vector<bool>& vis, int par, int src){

        vis[src] = true;

        for (int neigh : l[src]){
            if (!vis[neigh]){
                if(cycle_dict_helper(vis, src, neigh)){
                    return true;
                }
            }else if (neigh != par){
                return true;
            }
        }

        return false;

    }

    bool cycle_dict(){
        vector<bool> vis (V, false);

        for (int i=0; i<V; i++){
            if (!vis[i]){
                if (cycle_dict_helper(vis, -1, i)){
                    return true;
                }
            }
        }
        return false;

    }

};


int main(){

    graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(1, 4);

    // g.print();

    cout << g.cycle_dict() << endl;
    return 0;
}