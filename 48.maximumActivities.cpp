#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.second != b.second){
        return (a.second < b.second);
    }
    return (a.first < b.first);
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<pair<int,int>> v;
    int n = start.size();
    for(int i = 0;i<n;i++){
        v.push_back({start[i],finish[i]});
    }
    sort(v.begin(),v.end(),cmp);
    int ans = 0;
    int last = -1;
    for(int i = 0;i<n;i++){
        if(v[i].first >= last){
            ans++;
            last = v[i].second;
        }
    }
    return ans;
}