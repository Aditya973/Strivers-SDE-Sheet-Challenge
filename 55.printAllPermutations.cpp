#include <bits/stdc++.h> 

void funct(int ind,string &s,vector<string>& ans){
    if(ind == s.size()){
        ans.push_back(s);
        return;
    }
    for(int i = ind;i<s.size();i++){
        swap(s[ind],s[i]);
        funct(ind+1,s,ans);
        swap(s[ind],s[i]);
    }
}

vector<string> findPermutations(string &s) {
    // Write your code here.
    int n = s.size();
    vector<string> ans;
    funct(0,s,ans);
    return ans;
}