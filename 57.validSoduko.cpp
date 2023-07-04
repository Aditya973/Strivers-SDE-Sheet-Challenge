#include<bits/stdc++.h>

bool isValid(int row,int col,int num,vector<vector<int>>& mat){
    for(int i = 0;i<9;i++){
        if(mat[i][col] == num){
            return false;
        }
    }
    for(int j = 0;j<9;j++){
        if(mat[row][j] == num){
            return false;
        }
    }
    for(int i = 0;i<9;i++){
        if(mat[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == num){
            return false;
        }
    }
    return true;
}

bool funct(vector<vector<int>>& mat){
    bool ans = false;
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(mat[i][j] == 0){
                for(int k = 1;k<=9;k++){
                    if(isValid(i,j,k,mat)){
                        mat[i][j] = k;
                        if(funct(mat) == true){
                            return true;
                        }
                        mat[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    vector<vector<int>> mat(9,vector<int>(9,0));
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            mat[i][j] = matrix[i][j];
        }
    }
    return funct(mat);
}
