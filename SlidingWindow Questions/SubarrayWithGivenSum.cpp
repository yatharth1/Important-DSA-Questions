#include<bits/stdc++.h>
using namespace std;

bool isSumSubarray(vector<int>& v, int sum){
    int n = v.size();
    int curr_sum = v[0];
    int start = 0;
    for(int end = 1; end < n; end++){
        while(curr_sum > sum && start < end - 1){
            curr_sum -= v[start];
            start++;
        }
        if(curr_sum == sum) return true;
        if(end < n) curr_sum += v[end];
    }

    if(curr_sum == sum) return true;

    return false;
}

int main(){
    vector<int> vec = {1, 4, 20, 3, 10, 5};
    int sum = 33;
    bool ans = isSumSubarray(vec, sum);
    if(ans) cout << "Yes";
    else cout << "No";
}

