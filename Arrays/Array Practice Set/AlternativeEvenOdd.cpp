//Portion of Kadane's Algotihm can be applied here
#include<bits/stdc++.h>
using namespace std;

int alternativeEvenOdd(vector<int>& v){
    int res = 0;
    int curr =  0;
    for(int i = 0; i < v.size(); i++){
        if((v[i] % 2 == 0 && v[i-1] % 2 != 0) || (v[i] % 2 != 0 && v[i-1] % 2 == 0)){
            curr++;
            res = max(res, curr);
        }else{
            break;
        }
    }
    return res;
}
int main(){
    vector<int> vec = {1,4,5,6,9,9};
    int ans = alternativeEvenOdd(vec);
    cout << ans;
}