#include<bits/stdc++.h>
using namespace std;

bool isPossible(int node,vector<vector<int>>& adj,vector<int> color,int col){
    for(auto child:adj[node]){
        if(color[child] == col){
            return false;
        }
    }
    return true;
}

bool funct(int node,int m,vector<vector<int>>& adj,vector<int>& color,int n){
    if(node == n){
        return true;
    }
    for(int i = 1;i<=m;i++){
        if(isPossible(node,adj,color,i)){
            color[node] = i;
            if(funct(node+1,m,adj,color,n) == true){
                return true;
            }
            color[node] = 0;
        }
    }
    return false;
    
}

string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n = mat.size();
    vector<vector<int>> adj(n);
    vector<int> color(n+1);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(mat[i][j] == 1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    if(funct(0,m,adj,color,n)){
        return "YES";
    }
    return "NO";
}