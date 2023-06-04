long long nCr(int n,int r){
  long long res = 1;
  for(int i = 1;i<=r;i++){
    res *= (n-i+1);
    res /= i;
  }
  return res;
}

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long>> ans;
  for(int i = 1;i<=n;i++){
    vector<long long> v;
    for(int j = 1;j<=i;j++){
      v.push_back(nCr(i-1,j-1));
    }
    ans.push_back(v);
  }
  return ans;
}