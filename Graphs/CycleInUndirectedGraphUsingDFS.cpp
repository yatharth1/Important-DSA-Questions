#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isCycleUsingDfs(int node, int parent, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;

        for(auto it : adj[node])
        {
            if(!vis[it])
            {
               if(isCycleUsingDfs(it, parent, adj, vis))
               {
                   return true;
                } 
               else if(it != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool isCycle(int node, vector<int> adj[])
    {
        vector<int> vis(node, 0);
        int parent  = -1;
        for(int i = 0; i < node; i++)
        {
            if(!vis[i])
            {
                if(isCycleUsingDfs(node, parent,adj, vis));
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> adj[n+1];
        
        for(int i = 0; i < m; i++)
        {
             int x ,y;
            cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        Solution obj;
        bool ans = obj.isCycle(n, adj);
        if(ans) cout <<"Yes";
        else cout << "No";
    }

    return 0;
}