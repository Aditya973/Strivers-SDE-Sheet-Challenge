#include <bits/stdc++.h>
using namespace std;

void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    for(int i = 0;i<n;i++){
        if(max_heap.empty() || arr[i]<=max_heap.top()){
            max_heap.push(arr[i]);
        }
        else{
            min_heap.push(arr[i]);
        }
        if(max_heap.size() > min_heap.size()+1){
            int elem = max_heap.top();
            max_heap.pop();
            min_heap.push(elem);
        }
        else if(min_heap.size() > max_heap.size()){
            int elem = min_heap.top();
            min_heap.pop();
            max_heap.push(elem);
        }
        if((i+1)%2 == 0){
            cout<<(max_heap.top()+min_heap.top())/2<<" ";
        }
        else{
            cout<<max_heap.top()<<" ";
        }
    }
    
}