#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    map<int,int> mp;
    mp[0] = 1;
    int xr = 0;
    int ans = 0;
    int n = arr.size();
    for(int i = 0;i<n;i++){
        xr ^= arr[i];
        ans += mp[xr^x];
        mp[xr]++;
    }
    return ans;
}