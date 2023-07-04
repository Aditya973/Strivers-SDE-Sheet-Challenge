#include<bits/stdc++.h>
using namespace std;

bool isValid(int r,int c,vector<int>& row,vector<int>& v,int n,vector<int>& lowDiag,vector<int>& upperDiag){
    if(row[r]){
        return false;
    }
    if(lowDiag[r+c] || upperDiag[(n-1)+(c-r)]){
        return false;
    }
    return true;
    
}

void funct(int col,int n,vector<int>& row,vector<int>& v,vector<int>& lowDiag,vector<int>& upperDiag,vector<vector<int>>& ans){
    if(col == n){
        ans.push_back(v);
        return;
    }

    for(int i = 0;i<n;i++){
        if(isValid(i,col,row,v,n,lowDiag,upperDiag)){
            int index = (n*i)+(col%n);
            v[index] = 1;
            row[i] = 1;
            lowDiag[i+col] = 1;
            upperDiag[(n-1)+(col-i)] = 1;
            funct(col+1,n,row,v,lowDiag,upperDiag,ans);
            lowDiag[i+col] = 0;
            upperDiag[(n-1)+(col-i)] = 0;
            v[index] = 0;
            row[i] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<int> v(n*n,0);
    vector<int> lowDiagonal(2*n - 1,0);
    vector<int> upperDiagonal(2*n - 1,0);
    vector<vector<int>> ans;
    vector<int> row(n,0);
    funct(0,n,row,v,lowDiagonal,upperDiagonal,ans);
    
    return ans;
}