#include<bits/stdc++.h>
using namespace std;

bool pal(vector<int>& v)
{
    int i = 0;
    int j = v.size() - 1;
    int flag = 0;
        while(i < j)
        {
            if(v[i] == v[j])
            {
                i++;
                j--;
            }
              flag = 1;
        }

      if(flag == 0) return false;

      return true;

}

int main()
{
    vector<int> v = {1 ,2 ,1};
    bool ans = pal(v);
    if(ans)
        cout << "yes";
    else
        cout << "no";
    return 0;
}