// io
#include <iostream>
#include <cstdlib>
#include <cstdio>

// containers
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <vector>
#include <forward_list>

// algorithm
#include <algorithm>
#include <numeric>

using namespace std;

struct Tire {
    Tire() : children(26), end(false) {}
    vector<Tire *> children;
    bool end;
};

class WordDictionary {
public:
    WordDictionary() {
        root = new Tire();
    }
    
    void addWord(string word) {
        cache.insert(word);
        Tire *cur = root;
        for (char c : word) {
            if (!cur->children[c - 'a'])
                cur->children[c - 'a'] = new Tire();
            cur = cur->children[c - 'a'];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        if (cache.count(word))
            return true;
        return search(word, root, 0, root->end);
    }
private:
    Tire *root;
    unordered_set<string> cache;

    bool search(string word, Tire *node, int idx, bool end) {
        if (idx == word.size())
            return end;
        if (word[idx] == '.') {
            bool _res = false;
            for (int i = 0; i < 26; ++i) {
                if (node->children[i])
                    _res = _res || search(word, 
                                          node->children[i], 
                                          idx + 1, 
                                          node->children[i]->end);
            }
            return _res;
        } else {
            if (!node->children[word[idx] - 'a'])
                return false;
            return search(word, 
                          node->children[word[idx] - 'a'], 
                          idx + 1, 
                          node->children[word[idx] - 'a']->end);
        }
    }
};

int main() {
    WordDictionary wd;
    wd.addWord("dad");
    wd.addWord("mad");
    wd.addWord("pad");
    wd.addWord("bad");
    cout << wd.search("hello") << endl;
    cout << wd.search("mad") << endl;
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */