#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool cycleCheck(int n, vector<int> adj[],  vector<int> &vis, vector<int> &dfsVis)
    {
        vis[n] = 1;
        dfsVis[n] = 1;

        for(auto it : adj[n])
        {
            if(!vis[it])
            {
                if(cycleCheck(it, adj, vis, dfsVis)) return true;
            } else if(dfsVis[it])
            {
                return true;
            }
        }
        dfsVis[n] = 0;
        return false;
    }
public:
    bool isCycle(int n, vector<int> adj[])
    {
        vector<int> vis(n ,0);
        vector<int> dfsVis(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                if(cycleCheck(i, adj, vis, dfsVis)){
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
        int n , m;
        cin >> n >> m;

        vector<int> adj[n+1];
        int x, y;

        for(int i = 0;i < m; i++)
        {
            cin >> x >> y;
            adj[x].push_back(y); //Directed Graph
        }
        Solution obj;
        bool ans = obj.isCycle(n, adj);
        if(ans) cout << "yes";
        else cout << "no";
    }

    return 0;
}