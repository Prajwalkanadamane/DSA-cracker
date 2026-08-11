#include<bits/stdc++.h>
using namespace std;

bool f(int idx, int clr, vector<vector<int>>& edges, vector<int>& color){

    color[idx] = clr;

    for (auto neigh : edges[idx]){
        if (color[neigh] == -1){
            if (f(neigh, !clr, edges, color) == false) return false;
        }else if(color[neigh] = clr) return false;
    }
    return true;

}

int main(){

    vector<vector<int>> edges = {{1,2,3}, {0,2}, {0,1,3}, {0,2}};
    
    vector<int> color(edges.size(), -1);
    
        for (int i=0; i<edges.size(); i++){
            if (color[i] == -1){
                if(f(i, 0, edges, color) == false) {
                    cout << "Not a Bipartite" << endl;
                    return 0;
                }
            }
        }

        cout << "Graph is a Bipartite" << endl;
        return 0;

}