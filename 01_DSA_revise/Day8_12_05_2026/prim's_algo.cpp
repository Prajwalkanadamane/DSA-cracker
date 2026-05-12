#include<iostream>
#include<vector>
#include<queue>
// #include<list>
using namespace std;

int primMST(int V, vector<vector<pair<int, int>>> adj){
    int mstCost = 0;

    vector<bool> inMST(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});

    while(pq.size() > 0){
        auto p = pq.top();
        int wt = p.first;
        int u = p.second;

        pq.pop();

        if (!inMST[u]){
            inMST[u] = true;
            mstCost += wt;

            for (int i=0; i<adj[u].size(); i++){
                int v = adj[u][i].first;
                int w = adj[u][i].second;

                pq.push({w, v});
            }
        }
    }
    return mstCost;
}

int main(){
    int V = 4;
    vector<vector<pair<int, int>>> adj(V);

    adj[0].push_back({1, 10}); //v, wt
    adj[1].push_back({0, 10}); //v, wt

    adj[0].push_back({3, 30}); //v, wt
    adj[3].push_back({0, 30}); //v, wt

    adj[1].push_back({0, 10}); //v, wt
    adj[1].push_back({0, 10}); //v, wt

    adj[1].push_back({0, 10}); //v, wt
    adj[1].push_back({0, 10}); //v, wt

    adj[1].push_back({0, 10}); //v, wt
    adj[1].push_back({0, 10}); //v, wt

    cout << "Minimum cost of MST: " << primMST(V, adj) << endl;

    return 0;
}