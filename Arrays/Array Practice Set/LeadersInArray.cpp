#include<bits/stdc++.h>
using namespace std;

vector<int> Leaders(vector<int>& vec){
    int n = vec.size();
    vector<int> ans;
    int curr_leader = vec[n-1];
    ans.push_back(curr_leader);

    for(int i = n - 2; i >= 0; i++){
        if(vec[i] > curr_leader){
            curr_leader = vec[i];
            ans.push_back(curr_leader);
        }
    }

    return ans;
}

int main(){
    vector<int> v = {7,10,4,10,6,5,2};
    vector<int> result = Leaders(v);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    
    return 0;
}