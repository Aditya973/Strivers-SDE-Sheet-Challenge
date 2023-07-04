#include <bits/stdc++.h>

vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};

bool isValid(int x,int y,vector<vector<int>>& vis,vector<vector<int>>& maze,int n){
  if(x >= 0 && x < n && y >= 0 && y < n && !vis[x][y] && (maze[x][y] == 1)){
    return true;
  }
  return false;
}

void funct(int x, int y, vector<vector<int>> &vis, vector<vector<int>> &maze,
           vector<int> &path, vector<vector<int>> &ans,int n) {
  if (x == n - 1 && y == n - 1) {
    ans.push_back(path);
    return;
  }
  for(auto d:dir){
    int x1 = x+d[0];
    int y1 = y+d[1];
    if(isValid(x1,y1,vis,maze,n)){
      int index = (x1*n)+(y1%n);
      path[index] = 1;
      vis[x1][y1] = 1;
      funct(x1,y1,vis,maze,path,ans,n);
      path[index] = 0;
      vis[x1][y1] = 0;
    }
  }
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  vector<vector<int>> ans;
  vector<int> path(n*n);
  path[0] = 1;
  vector<vector<int>> vis(n,vector<int>(n,0));
  vis[0][0] = 1;
  funct(0,0,vis,maze,path,ans,n);
  return ans;
}