#include<bits/stdc++.h>
using namespace std;

double findMean(vector<int>& v)
{
    int n = v.size();
    double sum = 0;
    if(n == 0) return 0;

    for(int i = 0; i < n; i++)
    {
        sum += v[i];
    }

    return (sum / n);
}


double findMedian(vector<int>& v)
{
    int n = v.size();

    sort(v.begin(), v.end());
     if (n % 2 != 0)
        return (double)v[n / 2];
 
    return (double)(v[(n - 1) / 2] + v[n / 2]) / 2.0;
}

vector<int> mainFun(vector<int>& v)
{
    int n = v.size();

    double meanMainFunc = findMean(v);
    double medianMainFnc = findMedian(v);
    double diffMainFun = meanMainFunc - medianMainFnc;
    double ans = 0.0;
    vector<int> ansVec;

    for(int i = 0; i < n; i++)
    {
        vector<int> currentSubset;
        for(int j = i; j < n; j++)
        {
            currentSubset.push_back(v[j]);
            double meanCurrentSubset = findMean(currentSubset);
            double medianCurrentSubset = findMedian(currentSubset);
            double diffCurrentSubset = meanCurrentSubset - medianCurrentSubset;

            if(diffCurrentSubset > diffMainFun)
            {
                ans = diffCurrentSubset;
                ansVec[i] = currentSubset[j];
            }
        }

    }
    return ansVec;
}

int main()
{
    vector<int> b = {1,2,3,4};
    vector<int> out = mainFun(b);
    return 0;
}