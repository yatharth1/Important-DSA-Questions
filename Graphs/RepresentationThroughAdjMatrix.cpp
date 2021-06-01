#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define rep(i,a,b) for(int i = a; i < b; i++)


int main(){
    int n, m;
    cin >> n >> m;

    vvi adjm(n+1, vi(n+1, 0));

    rep(i,0,m)
    {
        int x, y;
        cin >> x >> y;

        adjm[x][y] = 1;
        adjm[y][x] = 1;
    }

    cout << "Adjaency matrix of above graph is represented by: " << endl;

    rep(i,0,n+1){
        rep(j,1,n+1){
            cout << adjm[i][j] <<" ";
        }
        cout << endl;
    }

    if(adjm[3][7] == 1){
        cout << "There is a edge between 3 and 7" << endl;
    }else{
        cout << "No edge";
    }

}