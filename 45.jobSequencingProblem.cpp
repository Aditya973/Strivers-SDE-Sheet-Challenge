#include <bits/stdc++.h> 
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
    return (a.second > b.second);
}

int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int n = jobs.size();
    vector<pair<int,int>> v;
    int maxDeadline = 0;
    for(int i = 0;i<n;i++){
        v.push_back({jobs[i][0],jobs[i][1]});
        maxDeadline = max(maxDeadline,jobs[i][0]);
    }
    sort(v.begin(),v.end(),cmp);
    int profit = 0;
    vector<int> slots(maxDeadline+1,-1);
    for(int i = 0;i<n;i++){
        for(int j = v[i].first;j>=1;j--){
            if(slots[j] == -1){
                slots[j] = i;
                profit += v[i].second;
                break;
            }
        }
    }
    return profit;
}
