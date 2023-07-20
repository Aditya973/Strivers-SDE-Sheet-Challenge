#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    for(int i = 0;i<k;i++){
        pq.push({kArrays[i][0],{i,0}});
    }
    vector<int> ans;
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        int i = curr.second.first;
        int j = curr.second.second;
        ans.push_back(curr.first);
        if(j+1 < kArrays[i].size()){
            pq.push({kArrays[i][j+1],{i,j+1}});
        }
    }
    return ans;
}
