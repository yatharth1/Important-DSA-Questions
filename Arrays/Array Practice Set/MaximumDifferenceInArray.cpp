#include<bits/stdc++.h>
using namespace std;

int maximumDifference(vector<int> vec){
    int n = vec.size();
    int res = vec[1] - vec[0];
    int minSoFar = vec[0];

    for(int i = 1; i < n; i++){
        minSoFar = min(minSoFar, vec[i]);
        res = max(res, vec[i] - minSoFar);
    }

    return res;
}
int main(){
    vector<int> v = {2,3,10,6,4,8,1};
    int ans = maximumDifference(v);
    cout << ans;
}