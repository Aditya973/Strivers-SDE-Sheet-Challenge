#include<bits/stdc++.h>
using namespace std;
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int,int> mp;
    for(int i = 0;i<n;i++){
        mp[arr[i]]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(auto it:mp){
        pq.push({it.second,it.first});
        if(pq.size() > k){
            pq.pop();
        }
    }
    vector<int> ans;
    for(int i = 0;i<k;i++){
        auto p = pq.top();
        pq.pop();
        ans.push_back(p.second);
    }
    return ans;
}