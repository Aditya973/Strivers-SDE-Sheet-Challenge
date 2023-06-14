#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            int k = j+1, l = n-1;
            while(k < l){
                long long sum = arr[i]+arr[k]+arr[j]+arr[l];
                if(sum == target){
                    return "Yes";
                }
                else if(sum < target){
                    k++;
                }
                else{
                    l--;
                }
            }
        }
    }
    return "No";
}
