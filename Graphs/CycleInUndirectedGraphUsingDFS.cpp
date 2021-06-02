#include<bits/stdc++.h>
using namepsace std;

class Solution{
public:
    bool isCycleUsingDfs(int node, vector<int> adj[], vector<int> &vis, vector<vector<int>> &storeDFS)
    {
        vector<int> parent(node, -1);
        storeDFS.push_back({});
        vis[node] = 1;

        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                isCycleUsingDfs(it, adj, vis, storeDFS)
            }
        }
    }
};