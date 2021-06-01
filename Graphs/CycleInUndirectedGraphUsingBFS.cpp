#include <bits/stdc++.h>
using namespace std;

class Solution{

public:

    bool cycleCheckUsingBFS(int node, vector<int> adj[], vector<int> &vis)
    {
        vector<int> parent(node, -1);

        queue<pair<int,int>> q;
        q.push({node, -1});
        vis[node] = 1;

        while(!q.empty())
        {
            int temp = q.front().first;
            int par = q.front().second;
            q.pop();

            for(auto it : adj[node])
            {
                if(!vis[it]){
                    q.push({it, node});
                    vis[it] = 1;
                }
                else if(par != it)
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
        for(int i = 0; i < node; i++)
        {
            if(!vis[i])
            {
                if(cycleCheckUsingBFS(i, adj, vis)){
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

        int x, y;
        vector<int> adj[n+1];

        for(int i = 0; i < m; i++)
        {
            cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        Solution obj;
        bool ans = obj.isCycle(n, adj);
        if(ans) cout << "Yes, There's a cycle present in our graph" << endl;
        else cout <<"No, there is no cycle in our graph " << endl;
    }

    return 0;
}





