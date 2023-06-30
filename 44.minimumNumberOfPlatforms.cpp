#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    int i = 0, j = 0;
    int plat = 0;
    int ans = 0;
    while(i < n && j < n){
        if(at[j] <= dt[i]){
            plat++;
            j++;
        }
        else{
            plat--;
            i++;
        }
        ans = max(ans,plat);
    }
    return ans;
}