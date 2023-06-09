#include <bits/stdc++.h> 

int merge(long long *arr,int low,int mid,int high){
    int ct = 0;
    int left = low;
    int right = mid+1;
    vector<int> temp;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            ct += (mid-left+1);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low; i<= high;i++){
        arr[i] = temp[i - low];
    }
    return ct;
}

int mergeSort(long long *arr,int low,int high){
    if(low >= high){
        return 0;
    }
    int ct = 0;
    int mid = (low+high)/2;
    ct += mergeSort(arr,low,mid);
    ct += mergeSort(arr,mid+1,high);
    ct += merge(arr,low,mid,high);
    return ct;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergeSort(arr,0,n-1);
}