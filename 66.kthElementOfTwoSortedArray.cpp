#include<bits/stdc++.h>
using namespace std;

int lessThanOrEqualTo(int num,vector<int>& row){
    int n = row.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(row[mid] <= num){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
    int low = 0;
    int high = 1e5;
    while(low <= high){
        int mid = (low+high)/2;
        int ct = 0;
        ct = lessThanOrEqualTo(mid,row1)+lessThanOrEqualTo(mid,row2);
        if(ct <= k-1){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}