#include <iostream>
using namespace std;

int BinarySearch(int a[], int n, int key){
    int start = 0;
    int end = n-1;

    while(start <= end){
        int mid = (start + end) / 2;

        if(a[mid] == key){
            return mid;
        }else if(key < a[mid]){
            end--;
        }else{
            start++;
        }
    }
    return -1;
}

int main(){
    int n,key;
    cin >> n >> key;

    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = BinarySearch(arr,n,key);
    cout << ans;


}