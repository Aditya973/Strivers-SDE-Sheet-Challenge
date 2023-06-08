#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	sort(arr.begin(),arr.end());
	int ans = -1;
	for(int i = 1;i<n;i++){
		if(arr[i] == arr[i-1]){
			ans = arr[i];
			break;
		}
	}
	return ans;
}
