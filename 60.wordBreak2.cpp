#include <bits/stdc++.h> 
using namespace std;

bool isWord(int i,int j,string &s,map<string,int>& mp){
    string word = s.substr(i,j-i+1);
    if(mp[word]){
        return true;
    }
    return false;
}

void funct(int i,int j,string &s,string &p, vector<string>& ans,map<string,int>& mp){
    if(i == s.size()){
        ans.push_back(p);
        return;
    }
    if(j == s.size()){
        return;
    }
    p += s[j];
    funct(i,j+1,s,p,ans,mp);
    if(isWord(i,j,s,mp)){
        p += " ";
        funct(j+1,j+1,s,p,ans,mp);
        p.pop_back();
    }
    p.pop_back();
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    map<string,int> mp;
    int n = s.size();
    for(auto word:dictionary){
        mp[word] = 1;
    }    
    vector<string> ans;
    string p = "";
    funct(0,0,s,p,ans,mp);
    return ans;
}