#include <bits/stdc++.h>

bool searchMatrix(vector<vector<int>>& mat, int target) {
    bool ans = false;
    int m = mat.size();
    int n = mat[0].size();
    for(int i = 0;i<m;i++){
        if(target >= mat[i][0] && target <= mat[i][n-1]){
            int low = 0;
            int high = n-1;
            while(low <= high){
                int mid = (low+high)/2;
                if(mat[i][mid] == target){
                    ans = true;
                    break;
                }
                else if(mat[i][mid] > target){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
        }
    }
    return ans;
}