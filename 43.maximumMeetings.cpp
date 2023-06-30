#include <bits/stdc++.h> 

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<pair<int,pair<int,int>>> time;
    int n = start.size();
    for(int i = 0;i<n;i++){
        time.push_back({end[i],{i+1,start[i]}});
    }
    vector<int> ans;
    sort(time.begin(),time.end());
    int x = -1;
    for(int i = 0;i<n;i++){
        if(time[i].second.second > x){
            ans.push_back(time[i].second.first);
            x = time[i].first;
        }
    }
    // sort(ans.begin(),ans.end());
    return ans;
    
}