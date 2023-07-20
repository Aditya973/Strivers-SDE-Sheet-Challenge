#include <bits/stdc++.h>

void heapify(vector<int>& heap,int n,int ind){
    int smallest = ind;
    int left = 2*ind+1;
    int right = 2*ind+2;
    if(left < n && heap[left] < heap[smallest]){
        smallest = left;
    }
    if(right < n && heap[right] < heap[smallest]){
        smallest = right;
    }
    if(smallest != ind){
        swap(heap[ind],heap[smallest]);
        heapify(heap, n, smallest);
    }
}

void insert(int num,vector<int>& heap,int sz){
    heap.push_back(num);
    for(int i = (sz/2 -  1);i >= 0;i--){
        heapify(heap,sz,i);
    }
}

int delete_min(vector<int>& heap,int sz){
    int mini = heap[0];
    swap(heap[0],heap[sz-1]);
    heap.pop_back();
    heapify(heap,heap.size(),0);
    return mini;
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> heap;
    vector<int> ans;
    int sz = 0;
    for(auto query: q){
        if(query[0] == 0){
            sz++;
            insert(query[1],heap,sz);
        }
        else{
            ans.push_back(delete_min(heap,sz));
            sz--;
        }
    }
    return ans;
}
