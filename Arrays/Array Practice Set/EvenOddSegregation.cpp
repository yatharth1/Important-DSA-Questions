#include<bits/stdc++.h>
using namespace std;


void segregationFun(vector<int>& v)
{
    int n = v.size();
    int j =  -1;

    for(int i = 0; i < n; i++)
    {
        if(v[i] % 2 == 0)
        {
            j++;
            swap(v[i], v[j]);
        }
    }

}

int main()
{
    vector<int> v = {15, 14, 13, 12};
    int n = v.size();
    segregationFun(v);

    for(int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}