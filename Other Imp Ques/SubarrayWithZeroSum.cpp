#include<bits/stdc++.h>
using namespace std;

bool ans(vector<int>& v){
    int n = v.size();
    unordered_set<int> s;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
        if(sum == 0 || s.find(sum) != s.end()) 
            return true;

        s.insert(sum);
    }
    return false;
}

int main(){
    vector<int> v = {-3, 2, 3, 1, 6};
    bool res = ans(v);
    if(res) cout << "YES";
    else cout << "NO";
    return 0;
}