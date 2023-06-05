#include <bits/stdc++.h>

vector<long long int> generateRow(int row){
  vector<long long int> v;
  long long int res = 1;
  for(int col = 1;col <= row;col++){
    v.push_back(res);
    res *= (row-col);
    res /= (col);
  }
  return v;
}

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int>> ans;
  for(int i = 1;i<=n;i++){
    ans.push_back(generateRow(i));
  }
  return ans;
}
