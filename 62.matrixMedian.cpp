#include <bits/stdc++.h>

int countLessThanEqualToMid(int num,vector<int>& row){
    int l = 0;
    int h = row.size()-1;
    while(l <= h){
        int md = (l+h)/2;
        if(row[md] <= num){
            l = md+1;
        }
        else{
            h = md-1;
        }
    }
    return (l);
}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 1, high = 1e6;
    while(low <= high){
        int mid = (low + high)/2;
        int ct = 0;
        for(int i = 0;i<n;i++){
            ct += countLessThanEqualToMid(mid,matrix[i]);
        }
        if(ct <= (n*m)/2){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}