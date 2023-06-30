#include <bits/stdc++.h>
using namespace std;

void funct(int ind,vector<int>& arr,int n,int k,vector<int>& v,vector<vector<int>>& ans){
    if(ind == n){
        if(k == 0){
            ans.push_back(v);
        }
        return;
    }
    funct(ind+1,arr,n,k,v,ans);
    v.push_back(arr[ind]);
    funct(ind+1,arr,n,k-arr[ind],v,ans);
    v.pop_back();
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    
    vector<int> v;
    vector<vector<int>> ans;
    funct(0,arr,n,k,v,ans);
    return ans;
}