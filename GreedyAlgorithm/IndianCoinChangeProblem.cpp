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

    vi a(n);

    rep(i,0,n)
        cin >> a[i];
    
    int x;
    cin >> x;

    sort(a.begin(), a.end(), greater<int>());

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        ans += x/a[i];
        x -= x/a[i] * a[i];
    }

    cout << ans << endl;

    return 0;
}