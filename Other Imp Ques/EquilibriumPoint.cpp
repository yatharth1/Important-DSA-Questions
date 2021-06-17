#include<bits/stdc++.h>
using namespace std;

//compute prefix sum and suffix sum in same array
// check for every index if prefix_sum[i-1] == suffix_sum[i+1]  ==> return true;

bool isEquilibrium(vector<int> & v){
    int sum  = 0;
    for(int i = 0; i < v.size(); i++){
        sum += v[i];
    }

    int left_sum = 0;
    for(int i = 0; i < v.size(); i++){
        if(left_sum == sum - v[i]) return true;

        left_sum += v[i];
        sum -= v[i];
    }

    return false;
}
int main(){
    vector<int> v = {3, 4, 8, -9, 20, 6};
    bool ans = isEquilibrium(v);
    if(ans) cout << "YES";
    else cout << "NO";
}
