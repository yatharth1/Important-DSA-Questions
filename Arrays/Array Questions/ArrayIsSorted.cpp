#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i+1] < arr[i])
            return true;
    }

    return false;
}
int main()
{
    int arr[] = {5,4,3,2,1};
    int n = 5;
    bool ans = isSorted(arr, n);
    if(ans) cout << "True";
    else cout << "False";

}