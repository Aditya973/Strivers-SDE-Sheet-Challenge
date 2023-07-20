#include <bits/stdc++.h>

bool isPossible(int minDist,vector<int>& positions, int c, int n){
	int noOfPlayers = 1;
	int lastRoom = positions[0];
	for(int i = 1;i<n;i++){
		if(positions[i] - lastRoom >= minDist){
			noOfPlayers++;
			lastRoom = positions[i];
		}
	}
	if(noOfPlayers >= c){
		return true;
	}
	return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
	sort(positions.begin(),positions.end());
	int low = 1;
	int high = positions[n-1]-positions[0];
	while(low <= high){
		int mid = (low+high)/2;
		if(isPossible(mid,positions,c,n)){
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}
	return high;
}