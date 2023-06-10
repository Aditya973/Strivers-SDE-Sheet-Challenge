#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	int ans = 1;
	while(n){
		if(n & 1){
			ans = ((ans%m)*1ll*(x%m))%m;
		}
		x = ((x%m)*1ll*(x%m))%m;
		n = n >> 1;
	}
	return ans;
}