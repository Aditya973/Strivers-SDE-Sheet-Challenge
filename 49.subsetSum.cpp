#include<bits/stdc++.h>
using namespace std;

vector<int> subsetSum(vector<int> &num){
	// Write your code here.	
	vector<int> ans;
	int n = num.size();
	int subset_ct = 1 << n;
	for(int mask = 0;mask < subset_ct;mask++){
		int sum = 0;
		for(int i = 0;i<n;i++){
			if((1<<i)&mask){
				sum += num[i];
			}
		}
		ans.push_back(sum);
	}
	sort(ans.begin(),ans.end());
	return ans;
}