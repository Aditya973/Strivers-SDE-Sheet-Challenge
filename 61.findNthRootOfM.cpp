long long calc(int num,int n,int m){
  long long prod = 1;
  for(int i = 0;i<n;i++){
    prod *= num;
    if(prod > m){
      break;
    }
  }
  return prod;
}
int NthRoot(int n, int m) {
  // Write your code here.
  int low = 1, high = m;
  while(low <= high){
    int mid = (low + high)/2;
    long long prod = calc(mid,n,m);
    if(prod == m){
      return mid;
    }
    else if(prod > m){
      high = mid - 1;
    }
    else{
      low = mid+1;
    }
  }
  return -1;
}