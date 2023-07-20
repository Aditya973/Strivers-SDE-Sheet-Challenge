#include <bits/stdc++.h> 

struct Node {
    Node* links[26];
    
    bool containsKey(char ch){
        return (links[ch-'a'] != nullptr);
    }
    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};
class Trie {
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    int insert(int ind,string &word){
        int ct = 0;
        Node* node = root;
        for(int i = ind;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
                ct++;
            }
            node = node->get(word[i]);
        }
        return ct;
    }

};
int distinctSubstring(string &word) {
    //  Write your code here.
    int n = word.size();
    int ans = 0;
    Trie* obj = new Trie();
    for (int i = 0; i < n; i++) {
        ans += obj->insert(i,word);
    }
    return ans;
}
