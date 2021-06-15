#include<bits/stdc++.h>
using namespace std;

int maximumOnes(vector<bool>& v){
    int n = v.size();
    int res = 0;
    int curr = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == 0) curr = 0;
        else{
            curr++;
            res = max(res, curr);
        }
    }

    return res;
}
int main(){
vector<bool> v = {0,1,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1};
int ans = maximumOnes(v);
cout << ans;
}