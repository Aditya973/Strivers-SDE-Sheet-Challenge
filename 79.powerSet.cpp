#include <bits/stdc++.h> 
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    int n = v.size();
    int totalSubset = (1<<n);
    vector<vector<int>> subsets;
    for(int mask = 0;mask < totalSubset;mask++){
        vector<int> subset;
        for(int i = 0;i<n;i++){
            if((1<<i)&mask){
                subset.push_back(v[i]);
            }
        }
        subsets.push_back(subset);
    }
    return subsets;
}