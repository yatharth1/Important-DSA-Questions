#include<iostream>
using namespace std;

int peakElementInAnArray(int arr[], int n, int low, int high){
    
    int mid = (low + high) / 2;

    if((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == n-1 || arr[mid] > arr[mid + 1])){
        return mid;
    }
    else if (mid > 0 && arr[mid] > arr[mid - 1])
    {
        return peakElementInAnArray(arr, n, low, mid - 1);
    }

    else{
        return peakElementInAnArray(arr, n, mid + 1, high);
    }
    
}

int main(){

    int arr[] = {0, 6, 8, 5, 7, 9};
    int n = 6;
    int low = 0;
    int high = n - 1;

    cout << "peak element  index: " << peakElementInAnArray(arr, n, low, high) << endl;

    return 0;
}