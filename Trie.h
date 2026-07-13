#pragma once

#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class TrieNode{
    public:
        unordered_map<char,TrieNode*>children;
        bool isEnd;

        TrieNode(){
            isEnd=false;
        }
};

class Trie{
private:
    TrieNode* root;

public:
    Trie();
    void insert(const string& word);
    bool search(const string& word);
    vector<string> startsWith(const string& prefix);
    void remove(const string& word);

private:
    bool removeHelper(TrieNode* node, const string& word, int depth);
    void dfs(TrieNode* node, string& cur, vector<string>& ans);
};