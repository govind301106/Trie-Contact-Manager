#include "Trie.h"

Trie::Trie(){
    root=new TrieNode();
}

void Trie::insert(const string &word){
    TrieNode* cur=root;
    for(char ch:word){
        if(cur->children.find(ch)==cur->children.end()){
            TrieNode* newNode=new TrieNode();
            cur->children[ch]=newNode;
        }
        cur=cur->children[ch];
    }
    cur->isEnd=true;
}

bool Trie::search(const string& word){
    TrieNode* cur=root;
    for(char ch:word){
        if(cur->children.find(ch)==cur->children.end()){
            return false;
        }
        cur=cur->children[ch];
    }
    return cur->isEnd;
}

void Trie::dfs(TrieNode* node, string& cur, vector<string>& ans){

    if(node->isEnd)
        ans.push_back(cur);

    for(auto &child : node->children){

        cur.push_back(child.first);

        dfs(child.second, cur, ans);

        cur.pop_back();
    }
}

vector<string> Trie::startsWith(const string& prefix){

    TrieNode* cur = root;

    for(char ch : prefix){

        if(cur->children.find(ch) == cur->children.end())
            return {};

        cur = cur->children[ch];
    }

    vector<string> ans;
    string temp = prefix;

    dfs(cur, temp, ans);

    return ans;
}

void Trie::remove(const string& word) {

    if (!search(word))
        return;

    removeHelper(root, word, 0);
}

bool Trie::removeHelper(TrieNode* node, const string& word, int depth) {

    // Base Case: Reached the last character
    if (depth == word.size()) {

        node->isEnd = false;

        // If node has no children, tell parent it can delete this node
        return node->children.empty();
    }

    char ch = word[depth];
    TrieNode* child = node->children[ch];

    // Recur for the next character
    bool shouldDeleteChild = removeHelper(child, word, depth + 1);

    if (shouldDeleteChild) {

        delete child;
        node->children.erase(ch);

        // Tell parent whether this node can also be deleted
        return node->children.empty() && !node->isEnd;
    }

    return false;
}