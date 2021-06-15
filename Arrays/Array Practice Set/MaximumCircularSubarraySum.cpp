// find normal sum subaaray 
//find max circular sum subaaray by finding minimum sub array
// for ans-- find max of normal sum subarray and maximum circular sum array
// it will give TC of O(n)
#include<bits/stdc++.h>
using namespace std;

int normalMaxSum(vector<int>& v){
    int res = 0;
    int current_sum = 0;
    int n = v.size();
    for(int i = 0; i < n; i++){
        current_sum += v[i];
        if(current_sum < 0) current_sum = 0;
        else{
            res = max(res, current_sum);
        }
    }
    return res;
}

int overallMaxSum(vector<int>& v1){
    int n = v1.size();
    int maxSum = normalMaxSum(v1);
    if(maxSum < 0) return maxSum;
    int arr_sum = 0;
    for(int i = 0; i < n; i++){
        arr_sum += v1[i];
        v1[i] = -v1[i];
    }
    int circularSum = arr_sum + normalMaxSum(v1);
    return max(circularSum, maxSum);
}
int main(){
    vector<int> vec = {8,-4,3,-5,4};
    int ans = overallMaxSum(vec);
    cout << ans;
    return 0;
}