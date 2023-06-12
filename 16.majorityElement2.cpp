#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int ct1 = 0,ct2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;
    int n = arr.size();
    vector<int> ans;
    for(int i = 0;i<n;i++){
        if(ct1 == 0 && el2 != arr[i]){
            el1 = arr[i];
            ct1 = 1;
        }
        else if(ct2 == 0 && el1 != arr[i]){
            el2 = arr[i];
            ct2 = 1;
        }
        else if(arr[i] == el1){
            ct1++;
        }
        else if(arr[i] == el2){
            ct2++;
        }
        else{
            ct1--;
            ct2--;
        }
    }
    ct1 = 0;
    ct2 = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] == el1){
            ct1++;
        }
        if(arr[i] == el2){
            ct2++;
        }
    }
    if(ct1 > n/3){
        ans.push_back(el1);
    }
    if(ct2 > n/3){
        ans.push_back(el2);
    }
    return ans;
}