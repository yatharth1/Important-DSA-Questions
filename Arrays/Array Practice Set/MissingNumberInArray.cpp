#include<bits/stdc++.h>
using namespace std;

void checkMissing(vector<int> a){
    int n = a.size();
    int xor1 = 0;
    int xor2 = 0;
    for(int i = 0; i < n; i++)
    {
        xor1 = xor1^a[i];
        xor2 = xor2^(i+1);
    }

    cout << (xor1^xor2);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    checkMissing(a);
    return 0;
}