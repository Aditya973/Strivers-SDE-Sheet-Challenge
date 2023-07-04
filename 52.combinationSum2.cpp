#include<bits/stdc++.h>
using namespace std;

void funct(int ind,int targ,vector<int>& arr,vector<int>& v,vector<vector<int>>& ans){
	if(ind == arr.size()){
		if(targ == 0){
			ans.push_back(v);
		}
		return;
	}
	int k = 1;
	for(int i = ind+1;i<arr.size();i++){
		if(arr[ind] != arr[i]){
			break;
		}
		k++;
	}
	funct(ind+k,targ,arr,v,ans);
	if(arr[ind] <= targ){
		v.push_back(arr[ind]);
		funct(ind+1,targ-arr[ind],arr,v,ans);
		v.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<int> v;
	vector<vector<int>> ans;
	funct(0,target,arr,v,ans);
	sort(ans.begin(),ans.end());
	return ans;
}
