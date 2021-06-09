#include<bits/stdc++.h>
using namespace std;

int maxSum(vector<int> a)
{
    int currentSum = 0;
    int maxSum = INT_MIN;

    for(int i = 0; i < a.size(); i++)
        currentSum += a[i];
        if(currentSum < 0) currentSum = 0;
        maxSum = max(maxSum, currentSum);
    
    return maxSum;
}
int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i++)
        cin >> a[i];
    
    int ans = maxSum(a);
    cout << ans;
}