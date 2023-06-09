#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	long long eq1 = 0;
	long long eq2 = 0;
	long long sum = (n*1ll*(n+1))/2,sum2 = (n*1ll*(n+1)*(2*1ll*n+1))/6;
	for(int i = 0;i<n;i++){
		eq1 += arr[i];
		eq2 += arr[i]*1ll*arr[i];
	}
	eq1 -= sum;
	eq2 -= sum2;
	eq2 /= eq1;
	long long x = (eq1 + eq2)/2;
	long long y = x - eq1;
	int ct = 0;
	for(int i = 0;i<n;i++){
		if(arr[i] == x){
			ct++;
		}
	}
	if(ct == 2){
		return {(int)y,(int)x};
	}
	return {(int)x,(int)y};
}
