#include <bits/stdc++.h> 

struct Node{
    Node* links[26];
    bool flag;

    bool containsKey(char ch){
        return links[ch-'a'] != nullptr;
    }
    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string &word){
        Node* node = root;
        for(int i = 0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    void search(Node* node,string str,string& ans){
        if(str.size() > ans.size()){
            ans = str;
        }
        for(int i = 0;i<26;i++){
            if(node->get('a'+i) != nullptr && node->get('a'+i)->isEnd()){
                str += ('a'+i);
                search(node->get('a'+i),str,ans);
                str.pop_back();
            }
        }
    }
    Node* getRoot(){
        return root;
    }
};

string completeString(int n, vector<string> &a){
    // Write your code here.
    string ans = "";
    Trie* obj = new Trie();
    for(int i = 0;i<n;i++){
        obj->insert(a[i]);
    }
    obj->search(obj->getRoot(),"",ans);
    return (ans == "")?("None"):(ans);
}