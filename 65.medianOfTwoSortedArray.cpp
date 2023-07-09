int countLessThanEqualTo(int num,vector<int>&a){
	int low = 0;
	int high = a.size()-1;
	while(low <= high){
		int mid = (low+high)/2;
		if(a[mid] <= num){
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}
	return low;
}

int searchMedian(vector<int>& a, vector<int>& b,int md){
	int low = 1;
	int high = 1e9;
	while(low <= high){
		int mid = (low+high)/2;
		int ct = countLessThanEqualTo(mid, a)+countLessThanEqualTo(mid, b);
		if(ct <= md){
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}
	return low;
}

double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
	int n = a.size();
	int m = b.size();
	int totalLen = n+m;
	double ans = 0;
	if(totalLen % 2 == 0){
		int md1 = (totalLen/2) - 1;
		int md2 = totalLen/2;
		int num1 = searchMedian(a, b, md1);
		int num2 = searchMedian(a, b, md2);
		ans = ((double)num1+(double)num2)/2;
	}
	else{
		ans = searchMedian(a, b, totalLen/2);
	}
	return ans;
}