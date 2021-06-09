#include<bits/stdc++.h>
using namespace std;

int maxProfitStock(vector<int> a){
    int n = a.size();
    vector<int> helper(n);
    int maxProfit = INT_MIN;
    helper[n-1] = a[n-1];

    for(int i = n-2; i >= 0; i--)
        helper[i] = max(helper[i+1], a[i]);

    int currMax = helper[0] - a[0];

    for(int i = 1; i < n; i++)
        if(helper[i] - a[i] > currMax)
            currMax = helper[i] - a[i];
            maxProfit = max(maxProfit, currMax);
    
    return maxProfit;
}
int main()
{
    vector<int> a = {3,5,1,7,4,9,3};
    int ans = maxProfitStock(a);
    cout << ans;
}