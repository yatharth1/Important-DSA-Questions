#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define rep(i,a,b) for(int i = a; i < b; i++)

const int N = 1e5+2, MOD = 1e9+7;

//Declare adjancy list of array of vectors

vi adjList[N];

int main(){
    int n, m;
    cin >> n >> m;

    rep(i,0,m){
        int x , y;
        cin >> x >> y;

        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    cout << "Adjancy list of above graph is given by: " << endl;

    rep(i, 1, n+1)
    {
        cout << i << " -> ";
        for(int x: adjList[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}