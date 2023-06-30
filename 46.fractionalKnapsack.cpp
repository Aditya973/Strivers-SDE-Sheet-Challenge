#include <bits/stdc++.h> 
using namespace std;

bool cmp(pair<double,pair<int,int>> a,pair<double,pair<int,int>> b){
    if(a.first != b.first){
        return (a.first > b.first);
    }
    return (a.second.first > b.second.first);
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    vector<pair<double,pair<int,int>>> v;
    for(int i = 0;i<n;i++){
        v.push_back({items[i].second/(items[i].first*1.0),{items[i].first,items[i].second}});
    }
    sort(v.begin(),v.end(),cmp);
    double ans = 0;
    int i = 0;
    while(i < n){
        if(v[i].second.first <= w){
            ans += v[i].second.second;
            w -= v[i].second.first;
        }
        else{
            ans += v[i].first * w;
            break;
        }
        i++;
    }
    
    return ans;
}