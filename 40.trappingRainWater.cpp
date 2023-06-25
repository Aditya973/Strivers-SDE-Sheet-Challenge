#include <bits/stdc++.h> 
long fillWater(int i,int j,long *arr,long edge){
    long sum = 0;
    for(int k = i+1;k<=j-1;k++){
        if(arr[k] < edge){
            sum += (edge-arr[k]);
            arr[k] = edge;
        }
    }
    return sum;
}
long getTrappedWater(long *arr, int n){
    // Write your code here.
    if(n == 0 || n == 1 || n == 2){
        return 0;
    }
    int i = 0, j = n-1;
    long ans = 0;
    while(i < j){
        while(arr[i+1] >= arr[i]){
            i++;
        }
        while(arr[j-1] >= arr[j]){
            j--;
        }
        ans += fillWater(i,j,arr,min(arr[i],arr[j]));
    }
    return ans;
}