#include<bits/stdc++.h>
using namespace std;

//Mooore Voting Algorithm

int majorityElement(vector<int>& v){
    int n = v.size();
    int res = 0;
    int count = 1;
    for(int i = 1; i < n; i++){
        if(v[res] == v[i]){
            count++;
        }else{
            count--;
        }
        if(count == 0){
             res = i;
            count = 1;
        }
    }

    count = 0;
    for(int i = 0; i < n;i++){
        if(v[res] == v[i]) count++;
    }
    if(count <= n/2) return -1;
    return res;
}
int main(){
    vector<int> vec = {8,3,4,8,8};
    int ans = majorityElement(vec);
    cout << ans;
    return 0;
}