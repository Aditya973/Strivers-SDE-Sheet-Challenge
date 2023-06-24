#include<bits/stdc++.h>

int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int ans = 0;
    int i = 0, j = 0;
    while(j < n){
        if(arr[j] == 0){
            if(k > 0){
                k--;
                j++;
            }
            else{
                ans = max(ans,(j-i));
                if(arr[i] == 0){
                    k++;
                }
                i++;
            }
        }
        else{
            j++;
        }
    }
    ans = max(ans,(j-i));
    return ans;
}
