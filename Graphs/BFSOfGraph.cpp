#include<bits/stdc++.h>
using namespace std;

class solution
{
    public:
        vector<int> bfsOfGraph(int v, vector<int> adjList[])
        {
            vector<int> bfs;
            vector<int> vis(v, 0);
            for(int i = 0; i < v; i++)
            {
                if(!vis[i])
                {
                    queue<int> q;
                    q.push(i);
                    vis[i] = 1;
                    while(!q.empty())
                    {
                        int node = q.front();
                        q.pop();
                        bfs.push_back(node);

                        for(auto it : adjList[node])
                        {
                            if(!vis[it])
                            {
                                q.push(it);
                                vis[it] = 1;
                            }
                        }
                    }
                }
            }
            return bfs;
        }
};

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int v, e;
        cin >> v >> e;

        vector<int> adjList[v+1];

        for(int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        solution obj;
        vector<int> ans = obj.bfsOfGraph(v, adjList);
        for(int i = 1; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }

        cout << endl;
    }

    return 0;
}