#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int i = 0,j = 0;
	for(int j = 0;j<n;j++){
		if(j > 0 && arr[j] != arr[j-1]){
			arr[i+1] = arr[j];
			i++;
		}
	}
	return (i+1);
}