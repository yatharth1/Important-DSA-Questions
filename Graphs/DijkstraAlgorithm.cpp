#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX

void shortestPathDijkstra(int n, int src, vector<pair<int,int>> adj[])
{
    //dist, node ==> priority queue
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int dist[n];
    for(int i = 0; i< n; i++)
    {
        dist[i] = INF;
    }

    dist[src] = 0;
    pq.push(make_pair(0, src));

    while(!pq.empty())
    {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node])
        {
            if(dist[node] + it.second < dist[it.first]){
                dist[it.first] = dist[node] + it.second;
                pq.push(make_pair(dist[it.first], it.first));
            }
        }
    }

    cout << "The distnace from source, " << src << ", are : \n";
    for(int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> adj[n+1];

    int src;
    cin >> src;

    for(int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;

        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

    shortestPathDijkstra(n, src, adj);
}