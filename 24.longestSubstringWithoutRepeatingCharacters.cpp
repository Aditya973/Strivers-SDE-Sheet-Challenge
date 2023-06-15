#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    vector<int> mp(26,-1);
    int ans = 0;
    int n = input.size();
    int left = 0,right = 0;
    while(right < n){
        if(mp[input[right] - 'a'] != -1){
            while(left <= mp[input[right]-'a']){
                mp[input[left]-'a'] = -1;
                left++;
            }
        }
        mp[input[right] - 'a'] = right;
        ans = max(ans,right-left+1);
        right++;
    }
    return ans;

}