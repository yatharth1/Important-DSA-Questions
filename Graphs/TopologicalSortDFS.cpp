#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    void findTopoSort(int n, vector<int> adj[], vector<int> &vis, stack<int> &st)
    {
        vis[n] = 1;
        for(auto it : adj[n])
        {
            if(!vis[it])
            {
                findTopoSort(it, adj, vis, st);
            }
        }
        st.push(n);
    }
public:
    vector<int> topoSort(int n, vector<int> adj[])
    {
        vector<int> vis(n, 0);
        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                findTopoSort(i, adj, vis, st);
            }
        }

        vector<int> topo;
        while(!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n , m;
        cin >> n >> m;

        vector<int> adj[n+1];
        int x, y;
        for(int i = 0; i < m; i++)
        {
            cin >> x >> y;
            adj[x].push_back(y);
        }

        Solution obj;
        vector<int> ans = obj.topoSort(n, adj);
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] <<" ";
        }
        cout << endl;
    }
    return 0;
}