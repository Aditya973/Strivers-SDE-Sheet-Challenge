#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   map<int,int> mp;
   int n = arr.size();
   vector<vector<int>> ans;
   for(int i = 0;i<n;i++){
      int rem = s - arr[i];
      if(mp[rem]){
         vector<int> v = { rem, arr[i] };
         if(v[0] > v[1]){
            swap(v[0],v[1]);
         }
         for (int j = 0; j < mp[rem]; j++) {
           ans.push_back(v);
         }
      }
      mp[arr[i]]++;
   }
   sort(ans.begin(),ans.end());
   return ans;
}