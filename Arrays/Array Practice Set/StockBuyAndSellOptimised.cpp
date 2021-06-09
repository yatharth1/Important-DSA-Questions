#include<bits/stdc++.h>
using namespace std;

int maxProfitStock(vector<int> a){
    int n = a.size();
   
    int minSoFar = a[0];
    int maxProfit = INT_MIN;

    for(int i = 0; i < n; i++){
        minSoFar = min(minSoFar, a[i]);
        int profit = a[i] - minSoFar;
        maxProfit = max(maxProfit, profit );
    }
    return maxProfit;
}
int main()
{
    vector<int> a = {3,5,1,7,4,9,3};
    int ans = maxProfitStock(a);
    cout << ans;
}