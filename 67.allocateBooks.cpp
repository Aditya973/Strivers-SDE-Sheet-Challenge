#include <bits/stdc++.h>
using namespace std;
long long noOfDays(long long maxTime,vector<int>& time,int m,int n){
	long long days = 1;
	long long timeTaken = time[0];
	for(int i = 1;i<m;i++){
		if(days > n){
			break;
		}
		if(timeTaken+time[i] <= maxTime){
			timeTaken += time[i];
		}
		else{
			timeTaken = time[i];
			days++;
		}
	}
	return days; 
} 
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
	long long mx = 0;
	long long totalTime = 0;
	for(int i = 0;i<m;i++){
		totalTime += (long long)time[i];
		mx = max(mx,(long long)time[i]);
	}
	long long low = mx;
	long long high = totalTime;
	while(low <= high){
		long long mid = (low+high)/2;
		if(noOfDays(mid, time, m,n) > n){
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}
	return low;
}