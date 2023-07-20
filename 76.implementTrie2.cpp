#include <bits/stdc++.h> 

class Node{
    Node* links[26];
    int ct;
    int startWith;
    public:
    Node(){
        ct = 0;
        startWith = 0;
    }
    void inc(){
        startWith++;
    }
    void dec(){
        startWith--;
    }
    bool containsKey(char ch){
        return (links[ch-'a'] != nullptr);
    }
    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        ct++;
    }
    int getCount(){
        return ct;
    }
    int getPrefix(){
        return startWith;
    }
    void deleteWord(){
        ct--;
    }

};

class Trie{

    public:

    Node *root;
    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node *node = root;
        for(int i = 0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
            node->inc();
        }
        node->setEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;
        for(int i = 0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getCount();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;
        for(int i = 0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node* node = root;
        for(int i = 0;i<word.size();i++){
            node = node->get(word[i]);
            node->dec();
        }
        node->deleteWord();
    }
};
