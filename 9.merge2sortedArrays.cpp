#include <bits/stdc++.h>

void swapIfGreater(vector<int>& arr1,vector<int>& arr2,int i,int j){
	if(arr1[i] > arr2[j])
		swap(arr1[i],arr2[j]);
	else return;
}

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	int gap = (n+m)/2 + (n+m)%2;
	while(gap > 0){
		int left = 0;
		int right = left + gap;
		while(right < n+m){
			if(right < m){
				swapIfGreater(arr1, arr1, left, right);
			}
			else if(left < m && right >= m){
				swapIfGreater(arr1,arr2,left,right-m);
				
			}
			else if(left>=m){
				swapIfGreater(arr2,arr2,left-m,right-m);
				
			}
			left++; right++;
		}
		if(gap == 1){
			break;
		}
		gap = (gap)/2 + (gap)%2;
	}
	for(int i = 0;i<n;i++){
		arr1[m+i] = arr2[i];
	}
	return arr1;
}