#include <iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<unordered_map>


#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i,a,b) for(int i = a; i < b; i++)

int main()
{
    int n; 
    cin >> n;

    vector<vector<int>> v;

    for(int  i = 0; i < n; i++)
    {
        int start,end;
        cin >> start >> end;
        v.push_back({start, end});
    }

    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    });

    int take = 1;
    int end = v[0][1];

    for(int i  = 1; i < n; i++){
        if(v[i][0] >= end){
            take++;
            end = v[i][1];
        }
    }

    cout << take << "\n";
    return 0;
}