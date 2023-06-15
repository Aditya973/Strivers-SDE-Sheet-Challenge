#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_set<int> st;
    for(int i = 0;i<n;i++){
        st.insert(arr[i]);
    }
    int ans = 0;
    for(auto num : st){
        if(st.find(num-1) == st.end()){
            int ct = 1;
            int x = num;
            while(st.find(x+1) != st.end()){
                ct++;
                x++;
            }
            ans = max(ct,ans);
        }
    }
    return ans;
}