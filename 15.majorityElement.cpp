#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int ct = 0;
	int elem = arr[0];
	for(int i = 0;i<n;i++){
		if(ct == 0){
			ct = 1;
			elem = arr[i];
		}
		if(arr[i] == elem){
			ct++;
		}
		else{
			ct--;
		}
	}
	if(ct <= 0){
		return -1;
	}
	int cnt = 0;
	for(int i = 0;i<n;i++){
		if(arr[i] == elem){
			cnt++;
		}
	}
	if(cnt > n/2){
		return elem;
	}
	return -1;
}