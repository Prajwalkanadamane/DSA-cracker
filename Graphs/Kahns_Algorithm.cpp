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

    void KahnsSort(){
        vector<int> res;

        vector<int> indegree(V,0);
            for (int u=0; u<V; u++){
                for (int v:l[u]){
                    indegree[v]++;
                }
            }

        queue<int> q;

        for (int i=0; i<V; i++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for (int v: l[curr]){
                indegree[v]--;
                if (indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        for (int val:res){
            cout << val << " ";
        }
        cout << endl;

    }

};

int main(){
    Graph g(6);

    g.addEdge(3,1);
    g.addEdge(2,3);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(5,0);
    g.addEdge(5,2);

    // g.printAdjList();

    cout << "Kahn's Algorithm Sort: " << endl;
    g.KahnsSort();
    
    return 0;
}