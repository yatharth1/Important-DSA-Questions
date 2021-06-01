#include<iostream>
#include<climits>
using namespace std;

int minimumSubarraySize(int arr[], int n, int x){
    int ans = n+1;
    int sum = 0;
    int start = 0;
    int end = 0;

    while(end < n){
        while(sum <= x && end < n){
            sum += arr[end++]; 
        }

        while(sum > x && start < n){
            if(end - start < ans){
                ans = end - start;
            }
            sum -= arr[start++];
        }
    }
    return ans;
}

int main(){
    int arr[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n = 6;

    int minLength = minimumSubarraySize(arr, n, x);

    if(minLength == n+1){
        cout <<"No such subarray exists" << endl;
    }else{
        cout << "smallest length subarray is: " << minLength << endl;
    }
    return 0;
}