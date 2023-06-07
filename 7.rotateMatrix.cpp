#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int top = 0,right = m-1,left = 0,bottom = n-1;
    int rotation = min(n,m)/2;
    for(int k = 0;k<rotation;k++){
        for(int j = left;j <= right;j++){
            swap(mat[k][k],mat[top][j]);
        }
        top++;
        for(int i = top;i<=bottom;i++){
            swap(mat[k][k],mat[i][right]);
        }
        right--;
        for(int j = right;j>=left;j--){
            swap(mat[k][k],mat[bottom][j]);
        }
        bottom--;
        for(int i = bottom;i>=top;i--){
            swap(mat[k][k],mat[i][left]);
        }
        left++;
    }
}