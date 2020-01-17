#include <cstring>
struct TrieNode { 
    TrieNode(bool _isEnd = false) : isEnd(_isEnd) {
        memset(children, NULL, sizeof(children));
    }
    bool isEnd;
    TrieNode *children[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        deleteTree(root);    
    }
    
    void add(const string& word) {
        TrieNode *p = root;
        for(char c : word) {
            if(p->children[c - 'a'] == nullptr) {
                p->children[c - 'a'] = new TrieNode();
            }
            p = p->children[c - 'a'];
        }
        p->isEnd = true;
    }
    

    
    bool search(const string& word) {
        return helper(0, word, root);
    }
    
private:
    TrieNode *root;
        bool helper(int pos, const string& word, TrieNode *root) {
       for(int k = pos; k < word.size(); k++) {
           if(word[k] != '.') {
               if(root->children[word[k] - 'a']) {
                   root = root->children[word[k] - 'a'];
               }
               else {
                   return false;
               }
           }
           else {
               for(int j = 0; j < 26; j++) {
                   if(root->children[j] &&
                     helper(k + 1, word, 
                            root->children[j])) {
                       return true;
                   }
               }
               return false;
           }
       }
        return root->isEnd;
    }
    
    void deleteTree(TrieNode *&root) {
        if(!root) {
            return;
        }
        for(int i = 0; i < 26; i++) {
            if(root->children[i]) {
                deleteTree(root->children[i]);
            }
        }
        delete root;
        root = nullptr;
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        trie = new Trie();
    }
    
    ~WordDictionary() {
        delete trie;
    }
    /** Adds a word into the data structure. */
    void addWord(string word) {
        trie->add(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return trie->search(word);
    }
private:
    Trie *trie;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */