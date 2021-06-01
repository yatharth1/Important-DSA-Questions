#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--)
    {
        int noOfStops;
        cin >> noOfStops;

        vector<pair<int,int> > a(noOfStops);

        for(int i = 0; i < noOfStops; i++){
            cin >> a[i].first >> a[i].second;
        }

        int l , p;
        cin >> l >> p;

        for(int i = 0; i < noOfStops; i++)
        {
            a[i].first = l - a[i].first;
        }

        sort(a.begin(), a.end());

        int ans  = 0;
        int currentFuelCapacity = p;

        priority_queue<int, vector<int> > maxheap;
        bool flag  = 0;
        for(int i = 0; i < noOfStops; i++)
        {
            if(currentFuelCapacity >= l)
                break;
            while(currentFuelCapacity < a[i].first)
            {
                if(maxheap.empty())
                {
                    flag = 1;
                    break;
                }
                ans++;
                currentFuelCapacity += maxheap.top();
                maxheap.pop();
            }
            if(flag) break;
            maxheap.push(a[i].second);
        }

        if(flag)
        {
            cout << " - 1 " << endl;
            continue;
        }

        while(!maxheap.empty() && currentFuelCapacity < l)
        {
            currentFuelCapacity += maxheap.top();
            maxheap.pop();
            ans++;
        }

        if(currentFuelCapacity < l)
        {
            cout << "-1" << endl;
            continue;
        }

        cout << ans << endl;
    }
}