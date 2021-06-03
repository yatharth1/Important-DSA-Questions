#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> findTopoSortBFS(int n, vector<int> adj[])
    {
        queue<int> q;
        vector<int> indegree(n, 0);

        //counting indegree of every node first
        for(int i = 0; i < n; i++)
        {
            for(auto it : adj[n])
            {
                indegree[it]++;
            }
        }

        //pushing nodes which have indegree zero in our empty queue
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        // Ans now
        vector<int> topo;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return topo;
    }
};

int main()
{
    int n, m; cin >> n >> m;
    vector<int> adj[n+1];

    int x, y;
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
    }

    Solution obj;
    vector<int> ans = obj.findTopoSortBFS(n, adj);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}