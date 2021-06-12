#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int>& v, int low, int high){
    while(low < high){
        swap(v[low], v[high]);
        low++;
        high--;
    }
}


void leftRotateByD(vector<int>& vec, int d){
    int  n  = vec.size();
    reverse(vec, 0, d - 1);
    reverse(vec , d, n-1);
    reverse(vec, 0, n-1);

    for(int i = 0 ; i < n; i++)
        cout << vec[i] << " ";
   
}


int main(){
    vector<int> vec = {1,2,3,4,5};
    int d = 2;
    leftRotateByD(vec, d);
}