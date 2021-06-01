#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i, a, b) for(int i = a; i < b; i++)

int main()
{
    int k;
    cin >> k;

    vector<vector<int>> a(k);

    rep(i,0,k)
    {
        int size;
        cin >> size;

        a[i] = vector<int>(size);
        rep(j,0,size)
        {
            cin >> a[i][j];
        }
    }

    vector<int> idx(k,0);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    rep(i , 0, k)
    {
        pq.push({a[i][0], i});
    }

    vi ans;

    while(!pq.empty()){
    {
        pii x = pq.top();
        pq.pop();

        ans.push_back(x.first);

        if(idx[x.second] + 1 < a[x.second].size())
        {
            pq.push({a[x.second][idx[x.second] + 1 ], x.second});
        }
        idx[x.second] += 1;
    }
    }
    
    rep(i, 0, ans.size())
    {
        cout << ans[i] << endl;
    }

    return 0;
}