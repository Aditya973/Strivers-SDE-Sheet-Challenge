#include <bits/stdc++.h> 
struct Node{
    Node* links[2];
    
    bool containsKey(int bit){
        return (links[bit] != nullptr);
    }
    void put(int bit,Node* node){
        links[bit] = node;
    }
    Node* get(int bit){
        return links[bit];
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* node = root;
        for(int i = 31;i>=0;i--){
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num){
        int maxNum = 0;
        Node* node = root;
        for(int i = 31;i>=0;i--){
            int bit = (num>>i)&1;
            if(node->containsKey(1-bit)){
                maxNum = maxNum|(1<<i);
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

int maximumXor(vector<int> A)
{
    // Write your code here.
    int n = A.size();
    int ans = 0;
    Trie *obj = new Trie();
    for(int i = 0;i<n;i++){
        obj->insert(A[i]);
    }
    for(int i = 0;i<n;i++){
        int xr = obj->getMax(A[i]);
        ans = max(ans,xr);
    }   
    return ans;
}