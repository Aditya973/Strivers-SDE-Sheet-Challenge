#include <bits/stdc++.h> 

void funct(int ind,vector<int> &arr,vector<int>& v,vector<vector<int>>& ans,int n){
    if(ind >= n){
        ans.push_back(v);
        return;
    }
    int k = 1;
    for(int i = ind+1;i<n;i++){
        if(arr[i] != arr[ind]){
            break;
        }
        k++;
    }
    funct(ind+k,arr,v,ans,n);
    v.push_back(arr[ind]);
    funct(ind+1,arr,v,ans,n);
    v.pop_back();
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    vector<int> v;
    funct(0,arr,v,ans,n);
    sort(ans.begin(),ans.end());
    return ans;
}