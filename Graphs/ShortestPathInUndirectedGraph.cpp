#include<bits/stdc++.h>
using namespace std;

void shortestPath(int n, int src, vector<int> adj[])
{
    queue<int> q;
    int distance[n];

    for(int i = 0;i < n; i++)
        distance[i] = INT_MAX;

    q.push(src);
    distance[src] = 0;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto it : adj[node])
        {
            if(distance[node] + 1 < distance[it])
            {
                distance[it] = distance[node] + 1;
                q.push(it);
            }
        }
    }

    for(int i = 0; i<n; i++)
    {
        cout << distance[i] << " ";
    }
}
int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];

    for(int i = 0; i <= m; i++)
    {
        int x , y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    shortestPath(n, 0, adj);
}