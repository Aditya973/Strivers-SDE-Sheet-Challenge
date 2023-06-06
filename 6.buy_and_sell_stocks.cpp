#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n = prices.size();
    if(n == 1){
        return 0;
    }
    int ans = 0;
    int mn = prices[0];
    for(int i = 1;i<n;i++){
        ans = max(ans,prices[i]-mn);
        mn = min(mn,prices[i]);
    }
    return ans;
}