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

    for (int i = 0; i < n; i++){
        key[i] = INT_MAX;
        mst[i] = false; 
        parent[i] = -1;
    }

    key[0] = 0;
    parent[0] = -1;

    priority_queue< pair<int,int>, vector <pair<int,int>>, greater<pair<int,int>>> pq; //  min heap

    pq.push({0,0});

    while(!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();

        mst[node] = true;

        for(auto it : adj[node])
        {
            if(mst[it.first] == false && it.second < key[it.first])
            {
                key[it.first] = it.second;
                parent[it.first] = node;
                pq.push({key[it.first], it.first});
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << parent[i] << "-" << i << " \n";
    }

    return 0;
}
