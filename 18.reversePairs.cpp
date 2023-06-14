#include <bits/stdc++.h> 

int countPairs(vector<int>& arr,int low,int mid,int high){
	int left = low, right = mid+1;
	int ct = 0;
	while(left <= mid){
		while(right <= high && arr[left] > (2*arr[right])){
			right++;
		}
		ct += (right - (mid+1));
		left++;
	}
	return ct;
}

void merge(vector<int>& arr,int low,int mid,int high){
	int left = low, right = mid+1;
	vector<int> temp;
	while(left <= mid && right <= high){
		if(arr[left] <= arr[right]){
			temp.push_back(arr[left]);
			left++;
		}
		else{
			temp.push_back(arr[right]);
			right++;
		}
	}
	while(left <= mid){
		temp.push_back(arr[left]);
		left++;
	}
	while(right <= high){
		temp.push_back(arr[right]);
		right++;
	}
	for(int i = low;i<=high;i++){
		arr[i] = temp[i-low];
	}
}

int mergeSort(vector<int>& arr,int low,int high){
	if(low >= high){
		return 0;
	}
	int mid = (low+high)/2;
	int ct = 0;
	ct += mergeSort(arr,low,mid);
	ct += mergeSort(arr,mid+1,high);
	ct += countPairs(arr,low,mid,high);
	merge(arr,low,mid,high);
	return ct;
}

int reversePairs(vector<int> &arr, int n){
	// Write your code here.	
	return mergeSort(arr,0,n-1);
}