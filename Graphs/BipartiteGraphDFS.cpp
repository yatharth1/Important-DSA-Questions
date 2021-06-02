#include<bits/stdc++.h>
using namespace std;

bool bipartiteCheckDFS(int n, vector<int> adj[], int color[])
{
    color[n] = 1;

    for(auto it : adj[n])
    {
        if(color[it] == -1)
        {
            color[it] = 1 - color[n];

            if(!bipartiteCheckDFS(it, adj, color)){
                return false;
            }else if(color[it] == color[n]){
                return false;
            }
        }
    }
    return true;
}
bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color); 
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            if(!bipartiteCheckDFS(i, adj, color)) {
                return false;
            }
        } 
    }
    return true; 
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i = 0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }
    
    if(checkBipartite(adj, n)) {
        cout << "yes"; 
    } else {
        cout << "No"; 
    }
    return 0;
}