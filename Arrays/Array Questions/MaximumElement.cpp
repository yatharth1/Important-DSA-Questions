#include<iostream>
using namespace std;

int maxElement(int arr[], int n)
{
    int max = 0;
    int ans;
    for(int i = 0; i < n; i++){
        if(arr[i] > max)
            max = arr[i];
            ans = i;
    
    }

    return ans;
}

int main()
{
    int arr[] = {1,2,5,46,54,78,-54,-1};
    int hello = maxElement(arr, 6);
    cout << hello;
}