#include <bits/stdc++.h>
using namespace std;

bool isCyclicBFS(int n, vector<vector<int>> adj)
{
    vector<int> indegree(n , 0);
    queue<int> q;

    for(int i = 0; i < n; i++){
        for(auto it : adj[n])
        {
            indegree[it]++;
        }
    }

    for(int i = 0; i< n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    int cnt = 0; //Basically, if these is equal to our n which is total no of node, then there is topo sort and hence no cycle so return false
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;
        for(auto it : adj[node])
        {
            indegree[it]--;
            if(indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    if(cnt == n) return false;
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    int x, y;

    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;

        adj[x].push_back(y);
    }

    bool ans = isCyclicBFS(n, adj);
    if(ans) cout << "YES";
    else cout << "NO";

    return 0;
}