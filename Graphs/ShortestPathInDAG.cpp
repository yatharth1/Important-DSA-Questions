#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX

class Solution{
private:
 void findTopo(int n, vector<pair<int,int>> adj[], stack<int> &st, vector<int> &vis)
   {
     vis[n] = 1;
     for(auto it : adj[n])
     { 
         if(!vis[it.first]){
         findTopo(it.first,adj, st, vis);
         }
     }
     st.push(n);
   }
public:
    void shortestPath(int n, int src, vector<pair<int,int>> adj[])
    {
        stack<int> st;
        vector<int> vis(n,0);
        for(int i = 0; i < n; i++)
        {
            if(!vis[i]){
                findTopo(i, adj, st, vis);
            }
        }

        int distance[n];
        for(int i = 0; i < n; i++)
        {
            distance[i] = INF;
        }
        distance[src] = 0;

        while(!st.empty())
        {
            int node = st.top();
            st.pop();

            if(distance[node] != INF){
                for(auto it : adj[node])
                {
                    if(distance[node] + it.second < distance[it.first])
                    {
                        distance[it.first] = distance[node] + it.second;
                    }
                }
            }
        }

        for(int i = 0; i< n; i++)
        {
            if(distance[i] == INF) cout << "INF";
            else {
                cout << distance[i] << " ";
            }
        }

    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> adj[n];

    for(int i = 0; i< m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;

        adj[x].push_back({y,w});
        adj[y].push_back({x, w});
    }

    Solution obj;
    obj.shortestPath(n, 0, adj);
}