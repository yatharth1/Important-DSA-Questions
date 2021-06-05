#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> adj[n+1];

    for(int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;

        adj[x].push_back({y,wt});
        adj[y].push_back({x,wt});
    }

    int key[n];
    bool mst[n];
    int parent[n];

    for(int i = 0; i < n; i++)
    {
        key[i] = INF;
        mst[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int i = 0; i < n-1; i++)
    {
        int mini = INF, node;

        for(int v = 0; v < n; v++)
        {
            if(mst[v] == false && key[v] < mini)
            {
                mini = key[v];
                node = v;
            }
        }
        mst[node] = true;

        for(auto it : adj[node])
        {
            int v = it.first;
            int weight = it.second;
            if(mst[v] == false && weight < key[v]){
                key[v] = weight;
                parent[v] = node;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << parent[i] << " - " << i <<" \n";
    }

    return 0;
}