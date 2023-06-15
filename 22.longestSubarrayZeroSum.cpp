#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

    // Write your code here
    int n = arr.size();
    long long sum = 0;
    int ans = 0;
    unordered_map<long long,int> mp;
    for(int i = 0;i<n;i++){
      sum += arr[i];
      if(sum == 0){
        ans = max(ans,i+1);
      }
      int rem = sum;
      if(mp.find(rem) != mp.end()){
        ans = max(ans,(i - mp[rem]));
      }
      if(mp.find(sum) == mp.end()){
        mp[sum] = i;
      }
    }
    return ans;

}